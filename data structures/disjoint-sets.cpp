
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
		while (father[a] != a)
			a = father[a];
		return a;
	}

	void join(int a, int b)
	{
		father[root(a)] = father[root(b)];
	}
};


