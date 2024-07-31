#include <algorithm>  // For std::remove_if, std::sort
#include <iostream>
#include <vector>

using namespace std;

void demo_lambda() {
  // Basic Lambda Function
  auto greet = []() { cout << "Hello, World!" << endl; };
  greet();  // Output: Hello, World!

  // Lambda Function with Parameters
  auto add = [](int a, int b) -> int { return a + b; };
  int result = add(3, 4);
  cout << "Result of add(3, 4): " << result << endl;  // Output: Result: 7

  // Capturing Variables by Value
  int x = 10;
  auto printX = [x]() { cout << "Captured by value, x = " << x << endl; };
  x = 20;
  printX();  // Output: Captured by value, x = 10

  // Capturing Variables by Reference
  int y = 20;
  auto printY = [&y]() { cout << "Captured by reference, y = " << y << endl; };
  y = 30;
  printY();  // Output: Captured by reference, y = 30

  // Capturing All Variables by Value and by Reference
  int a = 10, b = 20;
  auto printAB = [=, &b]() {
    cout << "Captured by value, a = " << a
         << ", Captured by reference, b = " << b << endl;
  };
  a = 30;
  b = 40;
  printAB();  // Output: Captured by value, a = 10, Captured by reference, b =
              // 40

  // Using Lambda with Standard Algorithms

  // Example: Using std::remove_if to move zeros to the end
  vector<int> vec = {1, 0, 3, 0, 5, 0, 7, 8, 0, 10};
  cout << "Original vector: ";
  for (const int& elem : vec) {
    cout << elem << " ";
  }
  cout << endl;

  auto is_zero = [](int x) { return x == 0; };
  auto new_end = remove_if(vec.begin(), vec.end(), is_zero);

  cout << "Vector after std::remove_if (zeros moved to the end): ";
  for (const int& elem : vec) {
    cout << elem << " ";
  }
  cout << endl;

  // Example: Using std::sort with a custom comparator
  vector<int> numbers = {4, 2, 5, 1, 3};
  cout << "Unsorted vector: ";
  for (const int& num : numbers) {
    cout << num << " ";
  }
  cout << endl;

  sort(numbers.begin(), numbers.end(), [](int a, int b) {
    return a > b;  // Sort in descending order
  });

  cout << "Sorted vector in descending order: ";
  for (const int& num : numbers) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  demo_lambda();
  return 0;
}
