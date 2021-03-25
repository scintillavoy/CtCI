#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Time complexity: O(n), in which n is the length of string
// Hash table
bool IsUnique(string str) {
    unordered_set<char> check;
    for (const auto &c : str) {
        if (check.find(c) != check.end()) {
            return false;
        }
        check.insert(c);
    }
    return true;
}

// Time complexity: O(nlgn)
// Sort and compare adjacent characters
bool IsUnique2(string str) {
    sort(str.begin(), str.end());
    for (int i = 0; i < str.size()-1; ++i) {
        if (str[i] == str[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> test_case{"eghsjriv",        // true
                             "nlsocjesirqw",    // false
                             "a",               // true
                             "abbbbb"};         // false
    for (auto x : test_case) {
        cout << IsUnique(x) << endl;
    }
    for (auto x : test_case) {
        cout << IsUnique2(x) << endl;
    }
    return 0;
}
