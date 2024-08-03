#include "common_header.h"

template <typename T>
class Discretizer {
 public:
  // Constructor that takes a vector of integers and maps them to a continuous
  // range [0, n)
  Discretizer(const vector<T>& data) {
    for (auto value : data) {
      discretize(value);
    }
  }

  // Function to discretize a single value (inserts the value if it doesn't
  // exist and returns its index)
  int discretize(const T& value) {
    auto it = discretization_map.find(value);
    if (it == discretization_map.end()) {
      // Insert the new value with the next available index
      int new_index = discretization_map.size();
      discretization_map[value] = new_index;
      return new_index;
    }
    return it->second;
  }

  // Function to check if a value is in the discretization map
  bool contains(const T& value) const {
    return discretization_map.find(value) != discretization_map.end();
  }

 private:
  unordered_map<T, T> discretization_map;
};