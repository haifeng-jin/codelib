# Specify the source files for the main project
set(SOURCE_FILES
    graph/graph.h
    graph/shortest_path.h
    common_header.h
    binary_search.h
    discretizer.h
    grid.h
    random.cc
)

# Create the executable for the main project
add_executable(codelib ${SOURCE_FILES})

# Make SOURCE_FILES visible to parent and sibling directories
set(SOURCE_FILES ${SOURCE_FILES} PARENT_SCOPE)
