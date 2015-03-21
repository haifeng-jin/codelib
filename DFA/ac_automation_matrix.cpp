struct Trie
{
	int next[MAX_NODE_NUM][MAX_CHILD_NUM];
	int fail[MAX_NODE_NUM];
	int count[MAX_NODE_NUM];
	int node_cnt;
	bool vis[MAX_NODE_NUM]; //set it to false
	int root;

	void init()
	{
		node_cnt = 0;
		root = newnode();
	}

	int newnode()
	{
		for (int i = 0; i < MAX_CHILD_NUM; i++)
			next[node_cnt][i] = -1;
		count[node_cnt++] = 0;
		return node_cnt - 1;
	}

	int get_id(char a)
	{
		return a - 'A';
	}

	void insert(char buf[])
	{
		int now = root;
		for (int i = 0; buf[i]; i++)
		{
			int id = get_id(buf[i]);
			if (next[now][id] == -1)
				next[now][id] = newnode();
			now = next[now][id];
		}
		count[now]++;
	}

	void build()
	{
		queue<int>Q;
		fail[root] = root;
		for (int i = 0; i < MAX_CHILD_NUM; i++)
			if (next[root][i] == -1)
				next[root][i] = root;
			else
			{
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		while (!Q.empty())
		{
			int now = Q.front();
			Q.pop();
			for (int i = 0; i < MAX_CHILD_NUM; i++)
				if (next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else
				{
					fail[next[now][i]]=next[fail[now]][i];
					Q.push(next[now][i]);
				}
		}
	}

	int query(char buf[])
	{
		int now = root;
		int res = 0;

		memset(vis, 0, sizeof(vis));
		for (int i = 0; buf[i]; i++)
		{
			now = next[now][get_id(buf[i])];
			int temp = now;
			while (temp != root && !vis[temp])
			{
				res += count[temp];
 				// optimization: prevent from searching this fail chain again.
				//also prevent matching again.
				vis[temp] = true;
				temp = fail[temp];
			}
		}
		return res;
	}

	void debug()
	{
		for(int i = 0;i < node_cnt;i++)
		{
			printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],count[i]);
			for(int j = 0;j < MAX_CHILD_NUM;j++)
				printf("%2d",next[i][j]);
			printf("]\n");
		}
	}
}ac;

struct Matrix
{
	int order;
	int num[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

	Matrix()
	{}

	Matrix(int ord)
	{
		order = ord;
	}

	void init()
	{
		for (int i = 0; i < order; i++)
		{
			for (int j = 0; j < order; j++)
			{
				num[i][j] = 0;
			}
		}
	}
	void output()
	{
		for (int i = 0; i < order; i++)
		{
			for (int j = 0; j < order; j++)
			{
				printf("%d ", num[i][j]);
			}
			puts("");
		}
	}
};

Matrix operator*(Matrix ma, Matrix mb)
{
	int ord = ma.order;
	Matrix numc(ord);
	numc.init();
	int i, j, k;
	for (i = 0; i < ord; i++)
	{
		for (k = 0; k < ord; k++)
		{
			if (ma.num[i][k] == 0)
				continue;
			for (j = 0; j < ord; j++)
			{
				long long temp = ma.num[i][k] * (long long)mb.num[k][j];
				temp %= MOD;
				numc.num[i][j] += temp;
				numc.num[i][j] %= MOD;
			}
		}
	}
	return numc;
}

Matrix matrix_power(Matrix ma, int x)
{
	int ord = ma.order;
	Matrix numc(ord);
	numc.init();
	for (int i = 0; i < ord; i++)
	{
		numc.num[i][i] = 1;
	}
	for (; x; x >>= 1)
	{
		if (x & 1)
		{
			numc = numc * ma;
		}
		ma = ma * ma;
	}
	return numc;
}

void extract_matrix(Matrix &matrix)
{
	matrix.order = ac.node_cnt;
	matrix.init();
	for (int i = 0; i < ac.node_cnt; i++)
	{
		for (int j = 0; j < MAX_CHILD_NUM; j++)
		{
			if (ac.next[i][j] == NULL)
				continue;
			int temp = ac.next[i][j];
			if (ac.count[temp] == 0)
			{
				matrix.num[i][temp] += 1;
			}
		}
	}
}

