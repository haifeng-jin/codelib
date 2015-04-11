struct BIT
{
	LL binary_indexed_tree[MAX_N];

	void init()
	{
		memset(binary_indexed_tree, 0, sizeof(binary_indexed_tree));
	}

	int low_bit(int x)
	{
		return x & (-x);
	}

	void add(int pos, LL val)
	{
		for (int i = pos; i < MAX_N; i += low_bit(i))
		{
			binary_indexed_tree[i] += val;
		}
	}

	LL sum(int pos)
	{
		LL ret = 0;
		for (int i = pos; i > 0; i -= low_bit(i))
		{
			ret += binary_indexed_tree[i];
		}
		return ret;
	}
}
