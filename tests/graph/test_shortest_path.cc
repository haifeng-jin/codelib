#include <gtest/gtest.h>

#include "common_header.h"
#include "graph/shortest_path.h"

// Test case for the ShortestPath class
TEST(ShortestPathTest, DijkstraAlgorithm) {
  Graph g(5);
  g.add_edge(0, 1, 10);
  g.add_edge(0, 2, 3);
  g.add_edge(1, 2, 1);
  g.add_edge(1, 3, 2);
  g.add_edge(2, 1, 4);
  g.add_edge(2, 3, 8);
  g.add_edge(2, 4, 2);
  g.add_edge(3, 4, 7);
  g.add_edge(4, 3, 9);

  ShortestPath sp(g);
  sp.dijkstra(0);

  EXPECT_EQ(sp.get_distance(0), 0);
  EXPECT_EQ(sp.get_distance(1), 7);
  EXPECT_EQ(sp.get_distance(2), 3);
  EXPECT_EQ(sp.get_distance(3), 9);
  EXPECT_EQ(sp.get_distance(4), 5);
}
