#include <limits>
#include <queue>
#include <vector>

#include "common_header.h"
#include "graph.h"
#include "graph/graph.h"

using namespace std;

class ShortestPath {
 public:
  Graph &graph;
  vector<LL> distances;

  ShortestPath(Graph &graph) : graph(graph) {
    distances = vector<LL>(graph.num_nodes, numeric_limits<LL>::max());
  }

  void dijkstra(int start) {
    distances[start] = 0;
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>>
        pq;
    pq.push({0, start});

    while (!pq.empty()) {
      LL current_distance = pq.top().first;
      int current_node = pq.top().second;
      pq.pop();

      if (current_distance > distances[current_node]) continue;

      for (const Edge &edge : graph.edges[current_node]) {
        LL new_distance = current_distance + edge.weight;
        if (new_distance < distances[edge.node]) {
          distances[edge.node] = new_distance;
          pq.push({new_distance, edge.node});
        }
      }
    }
  }

  LL get_distance(int node) const { return distances[node]; }
};
