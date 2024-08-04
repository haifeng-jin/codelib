#include "grid.h"
#include "gtest/gtest.h"

TEST(PointTest, OperatorPlus) {
  Point p1(2, 3);
  Point p2(4, 5);
  Point expected(6, 8);
  EXPECT_EQ(p1 + p2, expected);
}

TEST(GridTest, OutOfBounds) {
  Grid grid(3, 3);
  EXPECT_TRUE(grid.out(Point(-1, 0)));
  EXPECT_TRUE(grid.out(Point(0, -1)));
  EXPECT_TRUE(grid.out(Point(3, 0)));
  EXPECT_TRUE(grid.out(Point(0, 3)));
  EXPECT_FALSE(grid.out(Point(1, 1)));
}

TEST(GridTest, Visited) {
  Grid grid(2, 2);
  grid.visit(Point(0, 0));
  EXPECT_TRUE(grid.visited(Point(0, 0)));
  EXPECT_FALSE(grid.visited(Point(1, 1)));
}

TEST(GridTest, Neighbours) {
  Grid grid(3, 3, directions_4);
  Point p(1, 1);
  vector<Point> expected = {Point(2, 1), Point(1, 2), Point(0, 1), Point(1, 0)};
  EXPECT_EQ(grid.neighbours(p), expected);
}

TEST(GridTest, Neighbours8) {
  Grid grid(3, 3, directions_8);
  EXPECT_EQ(grid.neighbours(Point(1, 1)).size(), 8);
  EXPECT_EQ(grid.neighbours(Point(0, 0)).size(), 3);
  EXPECT_EQ(grid.neighbours(Point(0, 1)).size(), 5);
}