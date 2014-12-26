int binary_indexed_tree[MAX_N];

int low_bit(int x)
{
	return x & (-x);
}

void add(int pos, int val)
{
	for (int i = pos; i < MAX_N; i += low_bit(i))
	{
		binary_indexed_tree[i] += val;
	}
}

int sum(int pos)
{
	int ret = 0;
	for (int i = pos; i > 0; i -= low_bit(i))
	{
		ret += binary_indexed_tree[i];
	}
	return ret;
}


