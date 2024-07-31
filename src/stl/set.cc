#include <iostream>
#include <set>
using namespace std;

void demo() {
  // Declare a set of integers
  // A set is implemented as a self-balanced binary search tree.
  set<int> mySet = {10, 20};

  // Insert elements into the set
  mySet.insert(30);
  mySet.insert(20);  // Duplicate elements are ignored

  // Print the elements in the set
  cout << "Elements in the set: ";
  for (const auto& elem : mySet) {
    cout << elem << " ";
  }
  cout << endl;

  // Check if an element exists in the set
  int value = 20;
  if (mySet.find(value) != mySet.end()) {
    cout << value << " exists in the set." << endl;
  } else {
    cout << value << " does not exist in the set." << endl;
  }

  // Erase an element from the set
  mySet.erase(20);

  // Print the elements in the set after deletion
  cout << "Elements in the set after erasing 20: ";
  for (const auto& elem : mySet) {
    cout << elem << " ";
  }
  cout << endl;

  // Size of the set
  cout << "Size of the set: " << mySet.size() << endl;

  // Clear all elements in the set
  mySet.clear();
  cout << "Size of the set after clearing: " << mySet.size() << endl;

  // Find lower bound
  // Note it also supports upper_bound.
  auto lb = mySet.lower_bound(25);
  if (lb != mySet.end()) {
    cout << "Lower bound of 25: " << *lb << endl;
  } else {
    cout << "No element not less than 25 found" << endl;
  }
}

void multiset_example() {
  multiset<int> myMultiset = {10, 20, 20, 30, 40, 50};

  auto lb = myMultiset.lower_bound(20);
  auto ub = myMultiset.upper_bound(20);

  cout << "multiset example:" << endl;
  cout << "Lower bound of 20: "
       << (lb != myMultiset.end() ? to_string(*lb) : "Not found") << endl;
  cout << "Upper bound of 20: "
       << (ub != myMultiset.end() ? to_string(*ub) : "Not found") << endl;

  // Get the next element after lower bound
  auto next_it = next(lb);
  if (next_it != myMultiset.end()) {
    cout << "Next element after lower bound: " << *next_it << endl;
  } else {
    cout << "No next element after lower bound" << endl;
  }
}

int main() {
  demo();
  multiset_example();
  return 0;
}
#include <iostream>
#include <set>
using namespace std;

void demo() {
  // Declare a set of integers
  // A set is implemented as a self-balanced binary search tree.
  set<int> mySet = {10, 20};

  // Insert elements into the set
  mySet.insert(30);
  mySet.insert(20);  // Duplicate elements are ignored

  // Print the elements in the set
  cout << "Elements in the set: ";
  for (const auto& elem : mySet) {
    cout << elem << " ";
  }
  cout << endl;

  // Check if an element exists in the set
  int value = 20;
  if (mySet.find(value) != mySet.end()) {
    cout << value << " exists in the set." << endl;
  } else {
    cout << value << " does not exist in the set." << endl;
  }

  // Erase an element from the set
  mySet.erase(20);

  // Print the elements in the set after deletion
  cout << "Elements in the set after erasing 20: ";
  for (const auto& elem : mySet) {
    cout << elem << " ";
  }
  cout << endl;

  // Size of the set
  cout << "Size of the set: " << mySet.size() << endl;

  // Clear all elements in the set
  mySet.clear();
  cout << "Size of the set after clearing: " << mySet.size() << endl;

  // Find lower bound
  // Note it also supports upper_bound.
  auto lb = mySet.lower_bound(25);
  if (lb != mySet.end()) {
    cout << "Lower bound of 25: " << *lb << endl;
  } else {
    cout << "No element not less than 25 found" << endl;
  }
}

void multiset_example() {
  multiset<int> myMultiset = {10, 20, 20, 30, 40, 50};

  auto lb = myMultiset.lower_bound(20);
  auto ub = myMultiset.upper_bound(20);

  cout << "multiset example:" << endl;
  cout << "Lower bound of 20: "
       << (lb != myMultiset.end() ? to_string(*lb) : "Not found") << endl;
  cout << "Upper bound of 20: "
       << (ub != myMultiset.end() ? to_string(*ub) : "Not found") << endl;

  // Get the next element after lower bound
  auto next_it = next(lb);
  if (next_it != myMultiset.end()) {
    cout << "Next element after lower bound: " << *next_it << endl;
  } else {
    cout << "No next element after lower bound" << endl;
  }
}

int main() {
  demo();
  multiset_example();
  return 0;
}
