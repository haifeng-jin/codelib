//first, call init_edge() and add all the edges using add_edge()
//then, call init_LCA(root).
//finally, call LCA(a, b) to quest the LCA of a and b.
//the graph can be both bidirected or unidirected.
const int MAX_NODE_NUM = 0;
const int MAX_EDGE = 0;
const int M= 0;

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

bool vis[MAX_NODE_NUM];
int father[MAX_NODE_NUM];
int power[M];
int st[MAX_NODE_NUM * 2][M];
int ln[MAX_NODE_NUM * 2];
int seq_cnt;
int seq[2*MAX_NODE_NUM];
int depth[2*MAX_NODE_NUM];
int first_appearance[MAX_NODE_NUM];

//returns the index of the first minimum value in [x, y]
void init_RMQ(int f[], int n)
{
	int i, j;
	for (power[0] = 1, i = 1; i < 21; i++)
	{
		power[i] = 2 * power[i - 1];
	}
	for (i = 0; i < n; i++)
	{
		st[i][0] = i;
	}
	ln[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		ln[i] = ln[i >> 1] + 1;
	}
	for (j = 1; j < ln[n]; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (i + power[j - 1] - 1 >= n)
			{
				break;
			}
			//for maximum, change ">" to "<"
			//for the last, change "<" or ">" to "<=" or ">="
			if (f[st[i][j - 1]] > f[st[i + power[j - 1]][j - 1]])
			{
				st[i][j] = st[i + power[j - 1]][j - 1];
			}
			else
			{
				st[i][j] = st[i][j - 1];
			}
		}
	}
}

int query(int x, int y)
{
	if(x > y)
	{
		swap(x, y);
	}
	int k = ln[y - x + 1];
	//for maximum, change ">" to "<"
	//for the last, change "<" or ">" to "<=" or ">="
	if (depth[st[x][k]] > depth[st[y - power[k] + 1][k]])
		return st[y - power[k] + 1][k];
	return st[x][k];
}


void dfs(int u ,int current_depth)
{
	vis[u] = true;
	first_appearance[u] = seq_cnt;
	depth[seq_cnt] = current_depth;
	seq[seq_cnt++] = u;
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (vis[v])
		{
			continue;
		}
		father[v] = u;
		if (!vis[v])
		{
			dfs(v, current_depth + 1);
			depth[seq_cnt] = current_depth;
			seq[seq_cnt++] = u;
		}
	}
}

void init_LCA(int root)
{
	memset(vis, 0, sizeof(vis));
	father[root] = -1;
	seq_cnt = 0;
	dfs(root, 0);
	init_RMQ(depth, seq_cnt);
}

//O(1)
int LCA(int u ,int v)
{
	int x = first_appearance[u];
	int y = first_appearance[v];
	int res = query(x, y);
	return seq[res];
}
