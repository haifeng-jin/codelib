#include <algorithm>  // For std::find
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// Function to tokenize a string with custom delimiters
vector<string> tokenize(const string& str, const string& delimiters) {
  vector<string> tokens;
  size_t start = 0;
  size_t end = str.find_first_of(delimiters);

  while (end != string::npos) {
    if (end > start) {
      tokens.push_back(str.substr(start, end - start));
    }
    start = end + 1;
    end = str.find_first_of(delimiters, start);
  }
  if (start < str.length()) {
    tokens.push_back(str.substr(start));
  }

  return tokens;
}

int main() {
  using namespace std;

  // Basic Operations
  string s1 = "Hello";
  string s2("World");
  string s3(s1);              // Copy constructor
  string s4 = s1 + " " + s2;  // Concatenation

  vector<char> chars = {'a', 'b', 'c'};
  string s5 = string(chars.begin(), chars.end()); // from a vector of chars, "abc"

  cout << "Concatenated string: " << s4 << endl;  // Output: Hello World

  // Input and Output
  string input;

  // Reading a single word
  cout << "Enter a single word: ";
  cin >> input;
  cout << "Single word input: " << input << endl;

  cin.ignore();  // Ignore leftover newline character

  // Reading a line of text
  cout << "Enter a line of text: ";
  getline(cin, input);
  cout << "Line input: " << input << endl;

  // Accessing Characters
  string s = "Hello";

  cout << "Characters in the string: ";
  for (size_t i = 0; i < s.length(); ++i) {
    cout << s[i] << " ";
  }
  cout << endl;

  // Substrings
  string sub = s4.substr(6, 5);          // Starting at index 6, length 5
  cout << "Substring: " << sub << endl;  // Output: World

  // Comparing Strings
  string s5 = "abc";
  string s6 = "abcd";

  if (s5 < s6) {
    cout << s5 << " is less than " << s6 << endl;
  } else {
    cout << s5 << " is not less than " << s6 << endl;
  }

  // Finding Substrings
  string s7 = "Hello World";
  string target = "World";

  // .find() is not implementing the KMP but a naive algorithm.
  size_t pos = s7.find(target);
  if (pos != string::npos) {
    cout << "Found " << target << " at position " << pos << endl;
  } else {
    cout << target << " not found" << endl;
  }

  // Replacing Substrings
  s7.replace(6, 5, "Universe");
  cout << "After replacement: " << s7 << endl;  // Output: Hello Universe

  // Tokenizing with Custom Delimiters
  string s8 = "This,is.a test;string";
  string delimiters = ",.; ";

  vector<string> tokens = tokenize(s8, delimiters);

  cout << "Tokens:" << endl;
  for (const auto& token : tokens) {
    cout << token << endl;
  }

  // Converting String to Number and Vice Versa
  string numStr = "12345";
  int num = stoi(numStr);
  cout << "String to number: " << num << endl;

  int num2 = 6789;
  string numStr2 = to_string(num2);
  cout << "Number to string: " << numStr2 << endl;

  // Example in a Competitive Programming Context
  string cpInput;
  cout << "Enter a string for vowel counting: ";
  getline(cin, cpInput);

  unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                'A', 'E', 'I', 'O', 'U'};

  int vowel_count = 0;
  for (char c : cpInput) {
    if (vowels.find(c) != vowels.end()) {
      vowel_count++;
    }
  }

  cout << "Number of vowels: " << vowel_count << endl;

  return 0;
}
