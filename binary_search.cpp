int binary_search(int start, int end, int a)
{
	int l = start;
	int r = end;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (ok(mid, a))
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}


