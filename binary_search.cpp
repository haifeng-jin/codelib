LL binary_search(LL start, LL end, LL a)
{
	LL l = start;
	LL r = end;
	while (l < r)
	{
		LL mid = (l + r) / 2;
		if (ok(mid, a))
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}


