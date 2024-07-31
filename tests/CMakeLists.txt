# Enable testing
enable_testing()

# Find all the test files
file(GLOB TEST_FILES test_binary_search.cc)

# Create a test executable
add_executable(test_runner ${TEST_FILES} ${CMAKE_SOURCE_DIR}/src/binary_search.cc )

# Link Google Test to the test executable
target_link_libraries(
  test_runner 
  GTest::gtest_main
)

target_include_directories(test_runner PRIVATE ${CMAKE_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(test_runner)