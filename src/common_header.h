#include <bits/stdc++.h>
using namespace std;

#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H

#define LL long long

// Create a 2D vector.
// Example: auto my2DVector = create2DVector<int>(3, 4, 0);
// It initialize a 2D vector of type int of size 3 rows and 4 columns with
// initial value of 0.
template <typename T>
vector<vector<T>> Create2DVector(size_t rows, size_t cols, T init_value) {
  return vector<vector<T>>(rows, vector<T>(cols, init_value));
}

#endif  // COMMON_HEADER_H