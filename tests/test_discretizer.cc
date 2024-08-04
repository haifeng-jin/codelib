#include <gtest/gtest.h>

#include "discretizer.h"  // Include the header file for the Discretizer class

TEST(DiscretizerTest, DiscretizeExistingValues) {
  vector<int> data = {5, 3, 6, 3, 9, 5, 3};
  Discretizer<int> discretizer(data);

  EXPECT_EQ(discretizer.get_index(3), 1);
  EXPECT_EQ(discretizer.get_index(5), 0);
  EXPECT_EQ(discretizer.get_index(6), 2);
  EXPECT_EQ(discretizer.get_index(9), 3);
}

TEST(DiscretizerTest, DiscretizeGetValue) {
  vector<int> data = {5, 3, 6, 3, 9, 5, 3};
  Discretizer<int> discretizer(data);

  EXPECT_EQ(discretizer.get_value(1), 3);
  EXPECT_EQ(discretizer.get_value(0), 5);
  EXPECT_EQ(discretizer.get_value(2), 6);
  EXPECT_EQ(discretizer.get_value(3), 9);
}

TEST(DiscretizerTest, DiscretizeSortedValues) {
  vector<int> data = {5, 3, 6, 3, 9, 5, 3};
  sort(data.begin(), data.end());
  Discretizer<int> discretizer(data);

  EXPECT_EQ(discretizer.get_index(3), 0);
  EXPECT_EQ(discretizer.get_index(5), 1);
  EXPECT_EQ(discretizer.get_index(6), 2);
  EXPECT_EQ(discretizer.get_index(9), 3);
}

TEST(DiscretizerTest, DiscretizeNewValues) {
  vector<int> data = {5, 3, 6, 3, 9, 5, 3};
  Discretizer<int> discretizer(data);

  EXPECT_EQ(discretizer.get_index(10), 4);
  EXPECT_EQ(discretizer.get_index(7), 5);
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