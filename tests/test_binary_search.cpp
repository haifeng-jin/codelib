#include <gtest/gtest.h>
#include "binary_search.h"
using namespace std;

TEST(BinarySearchTest, Test1) {
    EXPECT_EQ(ok(2, 3), false);
}

TEST(BinarySearchTest, Test2) {
    EXPECT_EQ(ok(4, 3), true);
}