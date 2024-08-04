#include "common_header.h"
#include 

class Dijkstra {
 public:
  priority_queue<Edge> pq;

  void dijkstra(int source) {
    fill(dist, dist + node_num, INF);
    dist[source] = 0;
    pq.push(Edge(0, -1, 0));
    while (!pq.empty()) {
      Edge a;
      a = pq.top();
      pq.pop();
      if (dist[a.v] != a.w) continue;
      for (int i = head[a.v]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        long long w = edge[i].w + a.w;
        if (dist[v] > w) {
          dist[v] = w;
          pq.push(Edge(v, -1, dist[v]));
        }
      }
    }
  }
};