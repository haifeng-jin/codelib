#include <gtest/gtest.h>

#include "binary_search.h"

TEST(BinarySearchTest, test_lower_bound_double) {
  double target = 3.5;
  double eps = 1e-5;
  auto compare = [target, eps](double value) {
    return value > target - eps;  // means value >= target
  };
  BinarySearch<double> search(compare);
  EXPECT_EQ(search.lower_bound(0, 5), 3.5);
}

TEST(BinarySearchTest, test_lower_bound_int) {
  int target = 3;
  auto compare = [target](int value) {
    return value >= target;  // means value >= target
  };
  BinarySearch<int> search(compare);
  EXPECT_EQ(search.lower_bound(0, 5), 3);
}

TEST(BinarySearchTest, test_lower_bound_exception) {
  int target = 5;
  auto compare = [target](int value) {
    return value >= target;  // means value >= target
  };
  BinarySearch<int> search(compare);
  EXPECT_THROW(search.lower_bound(0, 5), out_of_range);
}

TEST(BinarySearchTest, test_upper_bound_int) {
  int target = 3;
  auto compare = [target](int value) {
    return value >= target;  // means value >= target
  };
  BinarySearch<int> search(compare);
  EXPECT_EQ(search.upper_bound(0, 5), 2);
}

TEST(BinarySearchTest, test_upper_bound_exception) {
  int target = 0;
  auto compare = [target](int value) {
    return value >= target;  // means value >= target
  };
  BinarySearch<int> search(compare);
  EXPECT_THROW(search.upper_bound(0, 5), out_of_range);
}