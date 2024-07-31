#include <gtest/gtest.h>

#include "binary_search.h"
using namespace std;

TEST(BinarySearchTest, Test1) {
  BinarySearch search;
  EXPECT_EQ(search.search(0, 5, 3), 3);
}

TEST(BinarySearchTest, Test2) {
  BinarySearch search;
  EXPECT_EQ(search.search(0, 5, 4), 4);
}