struct Edge
{
	int v, next;
	long long w;
	Edge()
	{}
	Edge(int v, int next, long long w):v(v), next(next), w(w)
	{}
} edge[MAX_EDGE_NUM];

int head[MAX_NODE_NUM];
int edge_cnt;
int node_num, edge_num;

void init_edge()
{
	memset(head, -1, sizeof(head));
	edge_cnt = 0;
}

void add_edge(int u, int v, int w)
{
	edge[edge_cnt] = Edge(v, head[u], w);
	head[u] = edge_cnt++;
}


bool vis[MAX_NODE_NUM];
long long dist[MAX_NODE_NUM];
priority_queue<Edge> pq;

void dijkstra(int source)
{
	memset(vis, 0, sizeof(vis));
	fill(dist, dist + node_num, INF);
	dist[source] = 0;
	pq.push(Edge(0, -1, 0));
	while (!pq.empty())
	{
		int min_node = -1;
		Edge a;
		while (!pq.empty())
		{
			a = pq.top();
			min_node = a.v;
			if (!vis[a.v])
			{
				break;
			}
			pq.pop();
		}
		if (min_node == -1)
		{
			break;
		}
		vis[min_node] = true;
		for (int i = head[min_node]; i!= -1; i = edge[i].next)
		{
			int v = edge[i].v;
			long long w = edge[i].w;
			if (dist[v] > dist[min_node] + w)
			{
				dist[v] = dist[min_node] + w;
				pq.push(Edge(v, -1, dist[v]));
			}
		}
	}
}


