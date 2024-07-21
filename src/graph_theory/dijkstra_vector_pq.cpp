#define MAX_EDGE_NUM 0
#define MAX_NODE_NUM 0
#define INF (1LL << 60)

int node_num, edge_num;
long long dist[MAX_NODE_NUM];
vector<pair<int, int> > edge[MAX_NODE_NUM];

void input()
{
	scanf("%d%d", &node_num, &edge_num);
	for (int i = 0; i < edge_num; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		v--;
		u--;
		edge[u].push_back(make_pair(v, w));
		edge[v].push_back(make_pair(u, w));
	}
}

priority_queue<pair<long long, int> > pq;

void dijkstra(int source)
{
	fill(dist, dist + node_num, INF);
	dist[source] = 0;
	pq.push(make_pair(0LL, 0));
	for (int i = 0; i < node_num; i++)
		if (train[i])
		{
			pq.push(make_pair(-dist[i], i));
		}
	while (!pq.empty())
	{
		int u = pq.top().second;
		long long w = -pq.top().first;
		pq.pop();
		if (dist[u] != w)
			continue;
		for (int i = 0; i < (int)edge[u].size(); i++)
		{
			int v = edge[u][i].first;
			long long new_w = edge[u][i].second + w;
			if (dist[v] >= new_w && train[v])
			{
				train[v] = false;
			}
			if (dist[v] > new_w)
			{
				dist[v] = new_w;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}
}

