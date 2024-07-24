#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

auto initialize() {
    // Declare a map that maps strings to integers
     map< string, int> ageMap;

    // Insert key-value pairs into the map
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;
    return ageMap;
}

void map_insert(auto ageMap) {
    // Alternatively, you can use the insert method
    ageMap.insert(make_pair("David", 20));
    ageMap.insert({"Eve", 28});  // C++11 and later
}

void map_get(auto ageMap) {
    // Access and print values using keys
    cout << "Alice's age: " << ageMap["Alice"] << endl;
    cout << "Bob's age: " << ageMap["Bob"] << endl;
}

void map_find(auto ageMap) {
    // Check if a key exists
    string name = "Frank";
    if (ageMap.find(name) != ageMap.end()) {
        cout << name << "'s age: " << ageMap[name] << endl;
    } else {
        cout << name << " is not in the map." << endl;
    }    
}

void map_iterate(auto ageMap) {
    // Iterate over all key-value pairs in the map
    cout << "All entries in the map:" << endl;
    for (const auto& entry : ageMap) {
         cout << entry.first << ": " << entry.second << endl;
    }
}
    
void map_remove(auto ageMap) {
    // Erase an element by key
    ageMap.erase("Bob");    

    // Print the map after erasing an element
    cout << "After erasing Bob:" <<  endl;
    for (const auto& entry : ageMap) {
        cout << entry.first << ": " << entry.second <<  endl;
    }
}

void unordered_map() {
    // map is a binary search tree.
    // unordered_map is a hashmap.
    unordered_map<int, string> myUnorderedMap;

    // Insert elements
    myUnorderedMap[3] = "Three";
    myUnorderedMap[1] = "One";
    myUnorderedMap[4] = "Four";
    myUnorderedMap[2] = "Two";

    // Elements are not ordered by keys
    for (const auto& elem : myUnorderedMap) {
        cout << elem.first << ": " << elem.second << endl;
    }
}

int main() {
    auto ageMap = initialize();
    map_insert(ageMap);
    map_get(ageMap);
    map_find(ageMap);
    map_iterate(ageMap);
    map_remove(ageMap);
    unordered_map();
    return 0;
}
