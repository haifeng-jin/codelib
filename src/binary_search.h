#include "common_header.h"

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

/*
There should be a split.
The elements on the left of the split are not in the right half.
Return the left most element's index in the right half.
*/
class BinarySearch {
 public:
  LL target = 0;
  BinarySearch(LL target) : target(target) {}

  bool in_right_half(LL pos) { return pos >= target; }

  LL lower_bound(LL start, LL end) {
    LL left = start;
    LL right = end;
    while (left < right) {
      LL mid = (left + right) / 2;
      if (in_right_half(mid))
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};

#endif  // BINARY_SEARCH_H