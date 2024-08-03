#include "common_header.h"

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

/*
There should be a split.
The elements on the left of the split are not in the right half.
Return the left most element's index in the right half.
*/
template <typename T>
class BinarySearch {
 public:
  function<bool(T)> compare;
  BinarySearch(function<bool(T)> compare) : compare(compare) {}

  T lower_bound(const T& start, const T& end) {
    T pos = search(start, end);

    if (pos >= end) {
      throw out_of_range("Target beyond end.");
    }

    return pos;
  }

  T upper_bound(const T& start, const T& end) {
    T pos = search(start, end);

    if (pos >= end) {
      pos = end - 1;
    } else if (pos <= start) {
      throw out_of_range("Target below start.");
    }

    return pos;
  }

 private:
  T search(const T& start, const T& end) {
    T left = start;
    T right = end;
    while (left < right) {
      T mid = (left + right) / 2;
      if (compare(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

#endif  // BINARY_SEARCH_H