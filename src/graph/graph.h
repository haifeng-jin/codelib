#include "common_header.h"

#ifndef GRAPH_H
#define GRAPH_H

class Edge {
 public:
  int node;
  LL weight;
  Edge() {}
  Edge(int node, LL weight) : node(node), weight(weight) {}
};

class Graph {
 public:
  int num_nodes;
  int num_edges;
  vector<vector<Edge>> edges;
  Graph() {}
  Graph(int num_nodes = 0, int num_edges = 0)
      : num_nodes(num_nodes), num_edges(num_edges) {
    edges = vector<vector<Edge>>(num_nodes);
  }
  void add_edge(int a, int b, int weight) {
    edges[a].push_back(Edge(b, weight));
  }
};

#endif  // GRAPH_H