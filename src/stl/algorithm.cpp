#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void print_vector(const vector<int>& vec) {
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

struct Double {
    int key;
    string value;
};

// Custom comparison function
bool compare(const Double& a, const Double& b) {
    return a.key < b.key;
}

void demo_lower_bound() {
    vector<Double> vec = {
        {10, "ten"}, {20, "twenty"}, {20, "twenty"}, {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}
    };

    // Find lower bound for an element with key 20 using custom compare function
    // lower bound means the pointer of the first element that is >= the target.
    // The pointer is actually an iterator, too.
    Double target = {20, ""};
    auto lb = lower_bound(vec.begin(), vec.end(), target, compare);

    // Print result
    if (lb != vec.end()) {
        // Use distance() to get the index.
        cout << "Lower bound for key 20 is at index: " << distance(vec.begin(), lb)
                  << " with value: " << lb->value << endl;
    } else {
        cout << "Element not found" << endl;
    }
}

void demo_upper_bound() {
    vector<int> vec = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    // Upper bound
    auto ub = upper_bound(vec.begin(), vec.end(), 50);
    cout << "Upper bound of 50 is at index: " << distance(vec.begin(), ub) << endl;
}


void demo_find() {
    vector<int> vec = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // Find an element
    auto it = find(vec.begin(), vec.end(), 50);
    if (it != vec.end()) {
        cout << "Element found at index: " << distance(vec.begin(), it) << endl;
    } else {
        cout << "Element not found" << endl;
    }
}

void demo_sum() {
    vector<int> vec = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // Sum of elements
    int sum = accumulate(vec.begin(), vec.end(), 0); // Needs include numeric
    cout << "Sum of elements: " << sum << endl;
}

void demo_reverse() {
    vector<int> vec = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // Reverse the vector
    reverse(vec.begin(), vec.end());
    cout << "Reversed vector: ";
    print_vector(vec);
}


void demo_copy_if() {
    vector<int> vec = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // Filter elements greater than 50
    vector<int> filtered;
    copy_if(vec.begin(), vec.end(), back_inserter(filtered), [](int x) { return x > 50; });

    cout << "Filtered elements (greater than 50): ";
    print_vector(filtered);

}

void demo_find_if() {
    vector<int> vec = {10, 20, 30, 40, 50};

    // Predicate function to check if a number is greater than 25
    auto is_greater_than_25 = [](int x) {
        return x > 25;
    };

    // Using find_if to find the first element greater than 25
    auto it = find_if(vec.begin(), vec.end(), is_greater_than_25);

    // Check if an element was found
    if (it != vec.end()) {
        cout << "First element greater than 25 is: " << *it << endl;
    } else {
        cout << "No element greater than 25 found." << endl;
    }
}

void demo_swap() {
    // Initialize a vector with some elements
    vector<int> vec = {1, 2, 3, 4, 5};

    // Swap elements at positions 1 and 3
    swap(vec[1], vec[3]);

    // Print the vector after swapping
    cout << "Vector after swapping elements at positions 1 and 3: ";
    print_vector(vec);
    cout << endl;
}

int main() {
    vector_sort();
    vector_sort_descending();
    vector_sort_pair();
    vector_copy();

    demo_lower_bound();
    demo_upper_bound();
    demo_find();
    demo_sum();
    demo_reverse();
    demo_copy_if();
    demo_find_if();
    demo_swap();

    return 0;
}
