void dfs(int u, int parent) {
  dfn[u][0] = ++dfn_cnt;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v != parent) {
      dfs(v, u);
    }
  }
  dfn[u][1] = dfn_cnt;
}
