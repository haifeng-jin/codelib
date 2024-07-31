#define MAX_NODE_NUM 0
#define MAX_EDGE_NUM 0
#define INF 0x3f3f3f3f

struct Edge {
  int next, v, f;
  Edge() {}
  Edge(int next, int v, int f) : next(next), v(v), f(f) {}
} edge[MAX_EDGE_NUM * 2];

int head[MAX_NODE_NUM];
int q[MAX_NODE_NUM];
bool vis[MAX_NODE_NUM];
int cur[MAX_NODE_NUM];
int dep[MAX_NODE_NUM];
int edge_cnt;
int path[MAX_NODE_NUM];
int front, rear, q_size;

void add_edge(int u, int v, int f) {
  edge[edge_cnt] = Edge(head[u], v, f);
  head[u] = edge_cnt++;
  edge[edge_cnt] = Edge(head[v], u, 0);
  head[v] = edge_cnt++;
}

void init() {
  edge_cnt = 0;
  memset(head, -1, sizeof(head));
}

void q_init(int size) {
  front = 0;
  rear = 0;
  q_size = size;
}

void q_push(int a) {
  q[rear++] = a;
  rear %= q_size;
}

int q_pop() {
  int ret = q[front++];
  front %= q_size;
  return ret;
}

void bfs(int s, int t) {
  memset(vis, 0, sizeof(vis));
  memset(dep, -1, sizeof(dep));
  q_init(MAX_NODE_NUM);
  q_push(s);
  vis[s] = true;
  dep[s] = 0;
  while (front != rear && !vis[t]) {
    int u = q_pop();
    for (int i = head[u]; ~i; i = edge[i].next) {
      int v = edge[i].v;
      if (!vis[v] && edge[i].f > 0) {
        q_push(v);
        vis[v] = true;
        dep[v] = dep[u] + 1;
      }
    }
  }
}

int add_flow(int path[], int &path_n) {
  int min_edge = -1, delta = INF;
  for (int i = 0; i < path_n; ++i) {
    if (edge[path[i]].f < delta) {
      delta = edge[path[i]].f;
      min_edge = i;
    }
  }
  for (int i = 0; i < path_n; ++i) {
    edge[path[i]].f -= delta;
    edge[path[i] ^ 1].f += delta;
  }
  path_n = min_edge;
  return delta;
}

int last_node(int path[], int path_n, int s) {
  if (path_n) return edge[path[path_n - 1]].v;
  return s;
}

int find_next(int start) {
  for (int e = cur[start]; ~e; e = edge[e].next)
    if (edge[e].f && dep[start] + 1 == dep[edge[e].v]) return e;
  return -1;
}

int dfs(int s, int t) {
  int ret = 0;
  int path_n = 0;
  int x = s;
  memcpy(cur, head, sizeof(cur));
  while (true) {
    if (x == t) {
      ret += add_flow(path, path_n);
      x = last_node(path, path_n, s);
    }
    int next_edge = find_next(x);
    cur[x] = next_edge;
    if (next_edge == -1) {
      if (path_n == 0) break;
      dep[x] = -1;
      --path_n;
      x = last_node(path, path_n, s);
      continue;
    }
    path[path_n++] = next_edge;
    x = edge[next_edge].v;
  }
  return ret;
}

int dinic(int s, int t) {
  int ret = 0;
  while (true) {
    bfs(s, t);
    if (dep[t] == -1) return ret;
    ret += dfs(s, t);
  }
  return -1;
}
