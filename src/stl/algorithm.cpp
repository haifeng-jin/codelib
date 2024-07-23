#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const auto& vec) {
    for (auto& elem: vec) {
        cout << elem << ", ";
    }
    cout << endl;
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
    for (auto& elem: vec) {
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
    vector<int> vec(original.size());
    copy(original.begin(), original.end(), vec.begin());
    
    // Change the value of the original.
    original[2] = 100;
    
    // The copied vectors did not change.
    print_vector(original);
    print_vector(vec);
}

int main() {
    vector_sort();
    vector_sort_descending();
    vector_sort_pair();
    vector_copy();
    return 0;
}
