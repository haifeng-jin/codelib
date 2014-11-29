#define MAX_NODE_NUM 0
#define MAX_EDGE_NUM 0
#define MAX_Q_LEN MAX_NODE_NUM
#define M 30

struct Edge
{
	int v, next, id;
	Edge()
	{}
	Edge(int v, int next, int id):v(v), next(next), id(id)
	{}
} edge[MAX_EDGE_NUM];

int head[MAX_NODE_NUM];
int edge_cnt;

void init_edge()
{
	memset(head, -1, sizeof(head));
	edge_cnt = 0;
}

void add_edge(int u, int v, int id)
{
	edge[edge_cnt] = Edge(v, head[u], id);
	head[u] = edge_cnt++;
}

bool vis[MAX_NODE_NUM];
int father[MAX_NODE_NUM][M];
int depth[MAX_NODE_NUM];

template<typename T>
class queue
{
	T data[MAX_Q_LEN];
	int head, tail;

public:
	queue()
	{
		head = tail = 0;
	}

	bool empty()
	{
		return head == tail;
	}

	void pop()
	{
		head++;
		if (head >= MAX_Q_LEN)
			head = 0;
	}

	void push(T a)
	{
		data[tail++] = a;
		if (tail >= MAX_Q_LEN)
			tail = 0;
	}

	T front()
	{
		return data[head];
	}
};

void bfs(int root)
{
	queue<int> q;
	q.push(root);
	seq2_cnt = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = true;
		seq2[seq2_cnt++] = u;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			if (vis[v])
			{
				continue;
			}
			father[v][0] = u;
			depth[v] = depth[u] + 1;
			q.push(v);
		}
	}
}

//index start from 1.
void init_LCA(int root)
{
	fill_n(vis, node_num + 1, 0);
	memset(father, 0, sizeof(father));
	bfs(root);
	bool did;
	for (int i = 1; i < M; i++)
	{
		did = false;
		for (int j = 1; j <= node_num; j++)
		{
			int k = father[j][i - 1];
			if (k <= 0)
			{
				continue;
			}
			father[j][i] = father[k][i - 1];
			did = true;
		}
		if (!did)
		{
			break;
		}
	}
}

//O(log(n))
int LCA(int x, int y)
{
	if (depth[x] > depth[y])
	{
		swap(x, y);
	}
	int diff = depth[y] - depth[x];
	for (int i = 0; i < M && diff; i++)
	{
		if (diff & 1)
		{
			y = father[y][i];
		}
		diff >>= 1;
	}
	if (x == y)
	{
		return x;
	}
	int exp = 0;
	while (x != y)
	{
		if (!exp || father[x][exp] != father[y][exp])
		{
			x = father[x][exp];
			y = father[y][exp];
			exp++;
		}else
		{
			exp--;
		}
	}
	return x;
}


