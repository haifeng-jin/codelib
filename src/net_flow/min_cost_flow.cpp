
#define MAX_NODE_NUM 0
#define MAX_EDGE_NUM 0
#define N MAX_NODE_NUM
#define E MAX_EDGE_NUM * 2
#define INF 0x3f3f3f3f

struct Edge
{
	int next, v, c, w;
	Edge()
	{}
	Edge(int next, int v, int c, int w): next(next), v(v), c(c), w(w)
	{}
}edge[E];

int node_num, edge_cnt;
bool vis[N];
int head[N], pre[N], pre_edge[N];
int dist[N];
int src, sink;
int q[MAX_NODE_NUM];
int front, rear, q_size;

void q_init(int size)
{
	front = 0;
	rear = 0;
	q_size = size;
}

void q_push(int a)
{
	q[rear++] = a;
	rear %= q_size;
}

int q_pop()
{
	int ret = q[front++];
	front %= q_size;
	return ret;
}

bool q_empty()
{
	return front == rear;
}


void add_edge(int u, int v, int c, int w)
{
	edge[edge_cnt] = Edge(head[u], v, c, w);
	head[u] = edge_cnt++;
}

void add_edges(int u, int v, int c, int w)
{
	add_edge(u, v, c, w);
	add_edge(v, u, 0, -w);
}

void SPFA()
{
	memset(vis, 0, sizeof(vis));
	fill(dist, dist + node_num, INF);
	dist[src] = 0;
	pre[src] = src;
	vis[src] = true;
	q_init(node_num);
	q_push(src);
	while (!q_empty())
	{
		int u = q_pop();
		vis[u] = false;
		for (int i = head[u]; ~i; i = edge[i].next)
		{
			int v = edge[i].v;
			if (!edge[i].c || edge[i].w + dist[u] >= dist[v])
				continue;
			dist[v] = edge[i].w + dist[u];
			if (!vis[v])
			{
				vis[v] = true;
				q_push(v);
			}
			pre[v] = u;
			pre_edge[v] = i;
		}
	}
}

int mincost(int src, int sink)
{
	int flow = 0;
	int cost = 0;
	while (true)
	{
		memset(pre, -1, sizeof(pre));
		SPFA();
		if (-1 == pre[sink])
			break;
		int max_flow = INF;
		for (int i = sink; i != src; i = pre[i])
			if (edge[pre_edge[i]].c < max_flow)
				max_flow = edge[pre_edge[i]].c;
		flow += max_flow;
		cost += dist[sink] * max_flow;
		for (int i = sink; i != src; i = pre[i])
		{
			edge[pre_edge[i]].c -= max_flow;
			edge[pre_edge[i] ^ 1].c += max_flow;
		}
	}
	return cost;
}

void init()
{
	edge_cnt = 0;
	memset(head, -1, sizeof(head));
}
