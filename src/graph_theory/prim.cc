
#define MAX_EDGE_NUM 0
#define MAX_NODE_NUM 0
#define INF 0x3f3f3f3f

struct Edge {
  int v, next;
  double w;
  Edge() {}
  Edge(int v, int next, double w) : v(v), next(next), w(w) {}
} edge[MAX_EDGE_NUM];

int head[MAX_NODE_NUM];
int edge_cnt;
int node_num, edge_num;
double dist[MAX_NODE_NUM];
bool vis[MAX_NODE_NUM];

void init_edge() {
  memset(head, -1, sizeof(head));
  edge_cnt = 0;
}

void add_edge(int u, int v, double w) {
  edge[edge_cnt] = Edge(v, head[u], w);
  head[u] = edge_cnt++;
}

void input() {
  init_edge();
  for (int i = 0; i < node_num; i++) {
    int a, b;
    double w;
    scanf("%d%d%lf", &a, &b, &w);
    add_edge(a, b, w);
    add_edge(b, a, w);
  }
}

int find_best() {
  int ret = -1;
  double max_dist = INF;
  for (int i = 0; i < node_num; i++) {
    if (!vis[i] && dist[i] < max_dist) {
      ret = i;
      max_dist = dist[i];
    }
  }
  return ret;
}

void alter_neighbours(int u) {
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].v;
    double w = edge[i].w;
    dist[v] = min(dist[v], w);
  }
}

double prim(int s) {
  double ret = 0;
  fill(dist, dist + node_num, INF);
  memset(vis, 0, sizeof(vis));
  dist[0] = 0;
  int cnt = 0;
  while (true) {
    int u = find_best();
    if (u == -1) break;
    vis[u] = true;
    cnt++;
    ret += dist[u];
    alter_neighbours(u);
  }
  if (cnt < node_num) return -1;  // if the graph is not connected
  return ret;
}
