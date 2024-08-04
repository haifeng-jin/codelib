struct Edge {
  int v, next;
  long long w;
  Edge() {}
  Edge(int v, int next, long long w) : v(v), next(next), w(w) {}
} edge[MAX_EDGE_NUM];

int head[MAX_NODE_NUM];
int edge_cnt;
int node_num, edge_num;

void init_edge() {
  memset(head, -1, sizeof(head));
  edge_cnt = 0;
}

void add_edge(int u, int v, int w) {
  edge[edge_cnt] = Edge(v, head[u], w);
  head[u] = edge_cnt++;
}

bool vis[MAX_NODE_NUM];
long long dist[MAX_NODE_NUM];

void dijkstra(int source) {
  memset(vis, 0, sizeof(vis));
  fill(dist, dist + node_num, INF);
  dist[source] = 0;
  while (true) {
    int min_dist = INF;
    int min_node = -1;

    for (int i = 0; i < node_num; i++) {
      if (!vis[i] && dist[i] < min_dist) {
        min_dist = dist[i];
        min_node = i;
      }
    }
    if (min_node == -1) {
      break;
    }
    vis[min_node] = true;
    for (int i = head[min_node]; i != -1; i = edge[i].next) {
      int v = edge[i].v;
      int w = edge[i].w;
      dist[v] = min(dist[min_node] + w, dist[v]);
    }
  }
}
