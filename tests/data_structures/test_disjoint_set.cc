#include <gtest/gtest.h>

#include "common_header.h"
#include "data_structures/disjoint_set.h"

// Modify the DisjointSet class to remove the rank vector and the corresponding
// logic in unionSets

TEST(DisjointSetTest, Initialization) {
  DisjointSet ds(5);
  for (int i = 0; i < 5; ++i) {
    ASSERT_EQ(ds.find(i),
              i);  // Initially, each element should be its own parent
  }
}

TEST(DisjointSetTest, Union) {
  DisjointSet ds(5);
  ds.unionSets(0, 2);
  ASSERT_EQ(ds.find(0), ds.find(2));  // 0 and 2 should have the same parent

  ds.unionSets(4, 2);
  ASSERT_EQ(ds.find(4),
            ds.find(0));  // 4, 2, and 0 should all have the same parent
}

TEST(DisjointSetTest, PathCompression) {
  DisjointSet ds(5);
  ds.unionSets(0, 1);
  ds.unionSets(1, 2);
  ds.unionSets(2, 3);

  ds.find(0);  // This should trigger path compression

  ASSERT_EQ(ds.find(1),
            ds.find(3));  // 1 and 3 should now directly point to the root
}
