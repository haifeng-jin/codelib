#define MAX_EDGE_NUM 0
#define MAX_NODE_NUM 0

struct Edge
{
	int v, next;
	Edge()
	{}
	Edge(int v, int next):v(v), next(next)
	{}
} edge[MAX_EDGE_NUM];

int head[MAX_NODE_NUM];
int edge_cnt;

void init_edge()
{
	memset(head, -1, sizeof(head));
	edge_cnt = 0;
}

void add_edge(int u, int v)
{
	edge[edge_cnt] = Edge(v, head[u]);
	head[u] = edge_cnt++;
}
