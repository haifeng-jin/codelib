
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
		memset(vis, 0, sizeof(vis));
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
};


