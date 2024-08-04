vector<int> edge[MAX_N];
int degree[MAX_N];

void add_edge(int a, int b) {
  edge[a].push_back(b);
  degree[b]++;
}

void bfs(int node_num, vector<int> edge[]) {
  // indexes start from 0
  queue<int> q;
  for (int i = 0; i < node_num; i++) {
    if (degree[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    // push u into an array to get the topological order sequence
    for (int i = 0; i < (int)edge[u].size(); i++) {
      int v = edge[u][i];
      if (degree[v] == 0) {
        continue;
      }
      degree[v]--;
      if (degree[v] == 0) {
        q.push(v);
      }
    }
  }
  // if degree[i] != 0 now, it means there is a circle on the connected
  // component with vertex i.
}
