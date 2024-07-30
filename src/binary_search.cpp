#include "binary_search.h"

bool ok(int a, int b) {
	return a > b;
}

long long binary_search(long long start, long long end, long long a) {
	long long l = start;
	long long r = end;
	while (l < r)
	{
		long long mid = (l + r) / 2;
		if (ok(mid, a))
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}


