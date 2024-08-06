# Enable testing
enable_testing()

# Find all the test files
set(SOURCE_FILES
  graph/test_graph.cc
  graph/test_shortest_path.cc
  test_binary_search.cc
  test_discretizer.cc
  test_grid.cc
)

# Create a test executable
add_executable(test_runner ${SOURCE_FILES})

# Link Google Test to the test executable
target_link_libraries(
  test_runner 
  GTest::gtest_main
)

target_include_directories(test_runner PRIVATE ${CMAKE_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(test_runner)