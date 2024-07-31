#define MAX_X 0
#define MAX_Y MAX_X
#define MAX_EDGE_NUM 0
#define MAX_NODE_NUM MAX_X
// if xi and yj are connected, add (i, j) as an edge.
struct Edge {
  int v, next;
  Edge() {}
  Edge(int v, int next) : v(v), next(next) {}
} edge[MAX_EDGE_NUM];

int head[MAX_NODE_NUM];
int edge_cnt;
bool vis[MAX_X];
int match[MAX_X];
int x_num, y_num;

void init_edge() {
  memset(head, -1, sizeof(head));
  edge_cnt = 0;
}

void add_edge(int u, int v) {
  edge[edge_cnt].v = Edge(v, head[u]);
  head[u] = edge_cnt++;
}

bool find_match(int a) {
  for (int i = head[a]; ~i; i = edge[i].next) {
    int v = edge[i].v;
    if (vis[v]) continue;
    vis[v] = true;
    if (match[v] == -1 || find_match(match[v])) {
      match[v] = a;
      return true;
    }
  }
  return false;
}

int max_match() {
  memset(match, -1, sizeof(match));
  for (int i = 0; i < x_num; i++) {
    memset(vis, 0, sizeof(vis));
    find_match(i);
  }
  int ans = 0;
  for (int i = 0; i < y_num; i++)
    if (match[i] != -1) ans++;
  return ans;
}

void init_match(int x, int y) {
  x_num = x;
  y_num = y;
}
