// 1.call init_edge() and use add_edge() to insert all the edges.
// 2.call init_LCA()
// 3.call LCA(a, b) to get the LCA of a and b.
const int MAX_NODE_NUM = 0;
const int MAX_EDGE_NUM = 0;
const int MAX_Q_LEN = MAX_NODE_NUM;
const int M = 30;

struct Edge {
  int v, next, w;
  Edge() {}
  Edge(int v, int next, int w) : v(v), next(next), w(w) {}
} edge[MAX_EDGE_NUM];

int head[MAX_NODE_NUM];
int edge_cnt;

void init_edge() {
  memset(head, -1, sizeof(head));
  edge_cnt = 0;
}

void add_edge(int u, int v, int w) {
  edge[edge_cnt] = Edge(v, head[u], w);
  head[u] = edge_cnt++;
}

bool vis[MAX_NODE_NUM];
int father[MAX_NODE_NUM][M];
int depth[MAX_NODE_NUM];

template <typename T>
class queue {
  T data[MAX_Q_LEN];
  int head, tail;

 public:
  queue() { head = tail = 0; }

  bool empty() { return head == tail; }

  void pop() {
    head++;
    if (head >= MAX_Q_LEN) head = 0;
  }

  void push(T a) {
    data[tail++] = a;
    if (tail >= MAX_Q_LEN) tail = 0;
  }

  T front() { return data[head]; }
};

void bfs(int root) {
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].v;
      if (vis[v]) {
        continue;
      }
      father[v][0] = u;
      depth[v] = depth[u] + 1;
      q.push(v);
    }
  }
}

// index of the nodes start from 1.
void init_LCA(int root) {
  fill_n(vis, node_num + 1, 0);
  memset(father, 0, sizeof(father));
  bfs(root);
  bool did;
  for (int i = 1; i < M; i++) {
    did = false;
    for (int j = 1; j <= node_num; j++) {
      int k = father[j][i - 1];
      if (k <= 0) {
        continue;
      }
      father[j][i] = father[k][i - 1];
      did = true;
    }
    if (!did) {
      break;
    }
  }
}

// O(log(n))
int LCA(int x, int y) {
  if (depth[x] > depth[y]) {
    swap(x, y);
  }
  int diff = depth[y] - depth[x];
  for (int i = 0; i < M && diff; i++) {
    if (diff & 1) {
      y = father[y][i];
    }
    diff >>= 1;
  }
  if (x == y) {
    return x;
  }
  int exp = 0;
  while (x != y) {
    if (!exp || father[x][exp] != father[y][exp]) {
      x = father[x][exp];
      y = father[y][exp];
      exp++;
    } else {
      exp--;
    }
  }
  return x;
}
