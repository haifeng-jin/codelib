#include "common_header.h"

#ifndef DISCRETIZER_H
#define DISCRETIZER_H


template <typename T>
class Discretizer {
 public:
  // Constructor that takes a vector of integers and maps them to a continuous
  // range [0, n)
  Discretizer(const vector<T>& data) {
    for (auto value : data) {
      get_index(value);
    }
  }

  // Function to discretize a single value (inserts the value if it doesn't
  // exist and returns its index)
  int get_index(const T& value) {
    auto it = value_to_index.find(value);
    if (it == value_to_index.end()) {
      // Insert the new value with the next available index
      int new_index = value_to_index.size();
      value_to_index[value] = new_index;
      index_to_value.push_back(value);
      return new_index;
    }
    return it->second;
  }

  // Function to check if a value is in the discretization map
  bool contains(const T& value) const {
    return value_to_index.find(value) != value_to_index.end();
  }

  T get_value(const int& index) const {
    return index_to_value[index];
  }

 private:
  unordered_map<T, int> value_to_index;
  vector<T> index_to_value;
};

#endif  // DISCRETIZER_H