#include <gtest/gtest.h>

#include "binary_search.h"
using namespace std;

TEST(BinarySearchTest, Test1) {
  BinarySearch search(3);
  EXPECT_EQ(search.lower_bound(0, 5), 3);
}

TEST(BinarySearchTest, Test2) {
  BinarySearch search(4);
  EXPECT_EQ(search.lower_bound(0, 5), 4);
}