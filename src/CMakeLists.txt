# Specify the source files for the main project
set(SOURCE_FILES grammar.cc binary_search.h binary_search.cc common_header.h)

# Create the executable for the main project
add_executable(codelib ${SOURCE_FILES})

# Make SOURCE_FILES visible to parent and sibling directories
set(SOURCE_FILES ${SOURCE_FILES} PARENT_SCOPE)