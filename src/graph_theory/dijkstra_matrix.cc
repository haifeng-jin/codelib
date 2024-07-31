int vis[maxn];
int cost[maxn][maxn];
int lowcost[maxn];
int n;

void dijkstra(int beg) {
  int i, j, min;
  memset(vis, 0, sizeof(vis));
  vis[beg] = 1;
  for (i = 0; i < n; i++) lowcost[i] = cost[beg][i];
  lowcost[beg] = 0;
  int pre = beg;
  for (i = 1; i < n; i++) {
    min = inf;
    for (j = 0; j < n; j++)
      if (vis[j] == 0 && lowcost[pre] + cost[pre][j] < lowcost[j])
        lowcost[j] = lowcost[pre] + cost[pre][j];
    for (j = 0; j < n; j++)
      if (vis[j] == 0 && lowcost[j] < min) {
        min = lowcost[j];
        pre = j;
      }
    vis[pre] = 1;
  }
}
