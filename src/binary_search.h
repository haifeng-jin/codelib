#include "common_header.h"

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

/*
There should be a split.
The elements on the left of the split are not OK.
Return the left most OK element's index.
*/
class BinarySearch {
	public:

	BinarySearch() {}

	bool ok(LL a, LL b) {
		return a >= b;
	}

	LL search(LL start, LL end, LL a) {
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
};

#endif // BINARY_SEARCH_H