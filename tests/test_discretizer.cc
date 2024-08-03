#include <gtest/gtest.h>

#include "discretizer.h"  // Include the header file for the Discretizer class

TEST(DiscretizerTest, DiscretizeExistingValues) {
  vector<int> data = {5, 3, 6, 3, 9, 5, 3};
  Discretizer<int> discretizer(data);

  EXPECT_EQ(discretizer.discretize(3), 1);
  EXPECT_EQ(discretizer.discretize(5), 0);
  EXPECT_EQ(discretizer.discretize(6), 2);
  EXPECT_EQ(discretizer.discretize(9), 3);
}

TEST(DiscretizerTest, DiscretizeSortedValues) {
  vector<int> data = {5, 3, 6, 3, 9, 5, 3};
  sort(data.begin(), data.end());
  Discretizer<int> discretizer(data);

  EXPECT_EQ(discretizer.discretize(3), 0);
  EXPECT_EQ(discretizer.discretize(5), 1);
  EXPECT_EQ(discretizer.discretize(6), 2);
  EXPECT_EQ(discretizer.discretize(9), 3);
}

TEST(DiscretizerTest, DiscretizeNewValues) {
  vector<int> data = {5, 3, 6, 3, 9, 5, 3};
  Discretizer<int> discretizer(data);

  EXPECT_EQ(discretizer.discretize(10), 4);
  EXPECT_EQ(discretizer.discretize(7), 5);
}

TEST(DiscretizerTest, ContainsValues) {
  vector<int> data = {5, 3, 6, 3, 9, 5, 3};
  Discretizer<int> discretizer(data);

  EXPECT_TRUE(discretizer.contains(5));
  EXPECT_TRUE(discretizer.contains(3));
  EXPECT_TRUE(discretizer.contains(6));
  EXPECT_TRUE(discretizer.contains(9));
  EXPECT_FALSE(discretizer.contains(10));
  EXPECT_FALSE(discretizer.contains(7));
}