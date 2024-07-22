#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize a 1-d vector with a constant.
    auto vec = vector<int> (10, 1);
    for (auto value: vec) {
        cout << value << endl;
    }
    return 0;
}