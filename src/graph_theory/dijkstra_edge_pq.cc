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

long long dist[MAX_NODE_NUM];
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
