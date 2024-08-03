#!/bin/bash

# Function to print usage
print_usage() {
    echo "Usage: $0 [-f]"
    echo "  -f    Format files in place"
}

# Parse command-line options
FORMAT_IN_PLACE=false
while getopts "f" opt; do
    case $opt in
        f)
            FORMAT_IN_PLACE=true
            ;;
        *)
            print_usage
            exit 1
            ;;
    esac
done

# Detect the root directory of the git repository
REPO_ROOT=$(git rev-parse --show-toplevel)

# Exit if git command fails (e.g., not a git repository)
if [ $? -ne 0 ]; then
    echo "Error: This script must be run within a Git repository."
    exit 1
fi

# Change to the repository root directory
cd "$REPO_ROOT" || { echo "Failed to change directory to $REPO_ROOT"; exit 1; }

# Find all source files in the src and tests directories (adjust extensions as needed)
# Example includes .c, .h, .cpp, .hpp, and .cc files
SOURCE_FILES=$(find src tests -type f \( -name "*.c" -o -name "*.h" -o -name "*.cpp" -o -name "*.hpp" -o -name "*.cc" \))

# Check if clang-format is installed
if ! command -v clang-format &> /dev/null; then
    echo "clang-format could not be found. Please install clang-format."
    exit 1
fi

# Flag to check if any file is not correctly formatted
FORMAT_ERROR=0

# Function to check file formatting
check_format() {
    local file=$1
    echo "Checking $file"
    if ! clang-format -n -Werror "$file"; then
        echo "$file is not correctly formatted"
        FORMAT_ERROR=1
    fi
}

# Function to format file in place
format_file() {
    local file=$1
    echo "Formatting $file"
    clang-format -i "$file"
}

# Process each source file
for FILE in $SOURCE_FILES; do
    if [ "$FORMAT_IN_PLACE" = true ]; then
        format_file "$FILE"
    else
        check_format "$FILE"
    fi
done

if [ "$FORMAT_IN_PLACE" = false ] && [ $FORMAT_ERROR -ne 0 ]; then
    echo "Some files are not correctly formatted. Please run the script with the -f option to fix these issues."
    exit 1
elif [ "$FORMAT_IN_PLACE" = false ]; then
    echo "All files are correctly formatted."
fi
