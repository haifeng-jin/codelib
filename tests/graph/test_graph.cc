#include <gtest/gtest.h>

#include "common_header.h"
#include "graph/graph.h"

TEST(EdgeTest, ParameterizedConstructor) {
  int node = 1;
  LL weight = 10;
  Edge e(node, weight);
  EXPECT_EQ(e.node, node);
  EXPECT_EQ(e.weight, weight);
}

// Test case for the Graph class
TEST(GraphTest, DefaultConstructor) {
  Graph g;
  EXPECT_EQ(g.num_nodes, 0);
  EXPECT_EQ(g.num_edges, 0);
  EXPECT_TRUE(g.edges.empty());
}

TEST(GraphTest, ParameterizedConstructor) {
  int num_nodes = 5;
  int num_edges = 3;
  Graph g(num_nodes, num_edges);
  EXPECT_EQ(g.num_nodes, num_nodes);
  EXPECT_EQ(g.num_edges, num_edges);
  EXPECT_EQ(g.edges.size(), num_nodes);
}

TEST(GraphTest, AddEdge) {
  int num_nodes = 3;
  Graph g(num_nodes);

  int a = 0, b = 1, weight = 10;
  g.add_edge(a, b, weight);

  ASSERT_EQ(g.edges[a].size(), 1);
  EXPECT_EQ(g.edges[a][0].node, b);
  EXPECT_EQ(g.edges[a][0].weight, weight);

  // Add another edge
  a = 1;
  b = 2;
  weight = 20;
  g.add_edge(a, b, weight);

  EXPECT_EQ(g.num_edges, 2);
  ASSERT_EQ(g.edges[a].size(), 1);
  EXPECT_EQ(g.edges[a][0].node, b);
  EXPECT_EQ(g.edges[a][0].weight, weight);
}