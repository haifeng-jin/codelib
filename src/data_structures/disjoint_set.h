#include <vector>

#include "common_header.h"

class DisjointSet {
 public:
  DisjointSet(int size) : parent(size) {
    for (int i = 0; i < size; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
  }

  void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      parent[rootY] = rootX;  // Simply attach one root to the other
    }
  }

 private:
  std::vector<int> parent;
};
