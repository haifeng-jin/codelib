#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print_vector(const auto& vec) {
  for (auto& elem : vec) {
    cout << elem << ", ";
  }
  cout << endl;
}

void print_vector_2d(const auto& vec) {
  for (auto& row : vec) {
    print_vector(row);
  }
}

void vector_1d() {
  // Initialize a 1-d vector with a constant.
  auto vec = vector<int>(10, 1);
  print_vector(vec);
}

void vector_2d() {
  // Initialize a 2-d (3 by 4) vector.
  // The 5 is constant initial value, which is optional.
  vector<vector<int>> vec(3, vector<int>(4, 5));
  print_vector_2d(vec);
}

void vector_sort() {
  vector<int> vec({5, 4, 1, 2, 3});
  sort(vec.begin(), vec.end());
  print_vector(vec);
}

void vector_sort_descending() {
  vector<int> vec({5, 4, 1, 2, 3});
  // greater is a struct with a the "()" operator overridden.
  // So you can think it as a callable function.

  // The sort() function uses the 3rd parameter as the compare function.
  // The function should return a bool of whether the first element
  // should be placed before the second element after sorting.

  // When using greater() as the function means
  // when it is greater it should be put before.
  sort(vec.begin(), vec.end(), greater<int>());
  print_vector(vec);
}

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

void vector_copy() {
  vector<int> original = {1, 2, 3, 4, 5};

  // We show 4 different methods here.

  vector<int> copy_a(original);

  vector<int> copy_b = original;

  vector<int> copy_c;
  copy_c.assign(original.begin(), original.end());

  vector<int> copy_d(original.size());
  copy(original.begin(), original.end(), copy_d.begin());

  // Change the value of the original.
  original[2] = 100;

  // The copied vectors did not change.
  print_vector(original);
  print_vector(copy_a);
  print_vector(copy_b);
  print_vector(copy_c);
  print_vector(copy_d);
}

void vector_2d_copy() {
  // Initialize a 2D vector
  vector<vector<int>> original = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  // Use the copy constructor to create a new 2D vector
  vector<vector<int>> copy_a(original);

  vector<vector<int>> copy_b = original;

  vector<vector<int>> copy_c;
  copy_c.assign(original.begin(), original.end());

  vector<vector<int>> copy_d(original.size());
  copy(original.begin(), original.end(), copy_d.begin());

  // Change the value of the original.
  original[1][1] = 100;

  // The copied vectors did not change.
  print_vector_2d(original);
  print_vector_2d(copy_a);
  print_vector_2d(copy_b);
  print_vector_2d(copy_c);
  print_vector_2d(copy_d);
}

void vector_insert_delete() {
  vector<int> vec = {1, 2, 3, 4, 5};
  vec.insert(vec.begin() + 2, 100);
  vec.erase(vec.begin() + 3);
  vec.push_back(200);
  print_vector(vec);
}

int main() {
  vector_1d();
  vector_2d();
  vector_sort();
  vector_sort_descending();
  vector_sort_pair();
  vector_copy();
  vector_2d_copy();
  vector_insert_delete();
  return 0;
}
