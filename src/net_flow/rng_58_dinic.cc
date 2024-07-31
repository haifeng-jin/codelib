#define REP(i, n) for ((i) = 0; (i) < (int)(n); (i)++)
#define snuke(c, itr) \
  for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

typedef int F;
#define F_INF (1 << 29)
#define MAXV 1000
#define MAXE 1000  // E*2!

F cap[MAXE], flow[MAXE];
int to[MAXE], _prev[MAXE], last[MAXV], used[MAXV], level[MAXV];

struct MaxFlow {
  int V, E;

  MaxFlow(int n) {
    int i;
    V = n;
    E = 0;
    REP(i, V) last[i] = -1;
  }

  void add_edge(int x, int y, F f) {
    cap[E] = f;
    flow[E] = 0;
    to[E] = y;
    _prev[E] = last[x];
    last[x] = E;
    E++;
    cap[E] = 0;
    flow[E] = 0;
    to[E] = x;
    _prev[E] = last[y];
    last[y] = E;
    E++;
  }

  bool bfs(int s, int t) {
    int i;
    REP(i, V) level[i] = -1;
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (i = last[x]; i >= 0; i = _prev[i])
        if (level[to[i]] == -1 && cap[i] > flow[i]) {
          q.push(to[i]);
          level[to[i]] = level[x] + 1;
        }
    }
    return (level[t] != -1);
  }

  F dfs(int v, int t, F f) {
    int i;
    if (v == t) return f;
    for (i = used[v]; i >= 0; used[v] = i = _prev[i])
      if (level[to[i]] > level[v] && cap[i] > flow[i]) {
        F tmp = dfs(to[i], t, min(f, cap[i] - flow[i]));
        if (tmp > 0) {
          flow[i] += tmp;
          flow[i ^ 1] -= tmp;
          return tmp;
        }
      }
    return 0;
  }

  F maxflow(int s, int t) {
    int i;
    while (bfs(s, t)) {
      REP(i, V) used[i] = last[i];
      while (dfs(s, t, F_INF) != 0)
        ;
    }
    F ans = 0;
    for (i = last[s]; i >= 0; i = _prev[i]) ans += flow[i];
    return ans;
  }
};
