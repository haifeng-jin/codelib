
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

	int find(int a)
	{
		while (father[a] != a)
			a = father[a];
		return a;
	}

	void join(int a, int b)
	{
		father[find(a)] = father[find(b)];
	}
};


