#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool pair_sum_cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.first + a.second) > (b.first + b.second);
}

void print_pair_vector(const auto& vec) {
  for (auto& elem : vec) {
    cout << "(" << elem.first << ", " << elem.second << "), ";
  }
  cout << endl;
}

void vector_sort_pair() {
  vector<pair<int, int>> vec({{5, 4}, {1, 2}, {3, 7}});
  sort(vec.begin(), vec.end());
  print_pair_vector(vec);

  // Custom order for sort with the sum of the two elements
  sort(vec.begin(), vec.end(), pair_sum_cmp);
  print_pair_vector(vec);
}

int main() {
  vector_sort_pair();
  return 0;
}
