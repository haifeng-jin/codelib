
struct DSU
{
	int father[MAX_NODE_NUM];

	DSU()
	{}

	DSU(int n)
	{
		for (int i = 0; i < n; i++)
		{
			father[i] = i;
		}
	}

	int find(int a)
	{
		int ret = a;
		while (father[ret] != ret)
			ret = father[ret];
		while (father[a] != a)
		{
			int b = a;
			a = father[a];
			father[b] = ret;
		}
		return ret;
	}

	void merge(int a, int b)
	{
		father[find(a)] = father[find(b)];
	}
};


