
struct Disjoint_sets
{
	int father[MAX_NODE_NUM];

	Disjoint_sets()
	{}

	Disjoint_sets(int n)
	{
		for (int i = 0; i < n; i++)
		{
			father[i] = i;
		}
	}

	int root(int a)
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

	void join(int a, int b)
	{
		father[root(a)] = father[root(b)];
	}
};


