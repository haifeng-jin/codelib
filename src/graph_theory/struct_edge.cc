#define MAX_EDGE_NUM 0
#define MAX_NODE_NUM 0

struct Edge {
  int v, next;
  Edge() {}
  Edge(int v, int next) : v(v), next(next) {}
};

struct Graph {
  int head[MAX_NODE_NUM];
  int edge_cnt;
  Edge edge[MAX_EDGE_NUM];

  void init() {
    memset(head, -1, sizeof(head));
    edge_cnt = 0;
  }

  void add(int u, int v) {
    edge[edge_cnt] = Edge(v, head[u]);
    head[u] = edge_cnt++;
  }

  int next(int a) { return edge[a].next; }

  int v(int a) { return edge[a].v; }
};
