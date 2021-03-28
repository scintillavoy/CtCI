#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

// Time complexity: O(a + b)
// Hash table
bool CheckPermutation(string a, string b) {
    if (a.size() != b.size()) return false;
    unordered_map<char, int> check;
    for (const auto &c : a) {
        ++check[c];
    }
    for (const auto &c : b) {
        --check[c];
        if (check[c] < 0) {
            return false;
        }
    }
    return true;
}

// Time complexity: O(alga + blgb)
// Sorting and compare
bool CheckPermutation2(string a, string b) {
    if (a.size() != b.size()) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    cout << CheckPermutation("abcgdegfg", "gfedcgbga") << endl; // true
    cout << CheckPermutation("abecdeefg", "gfaedcbae") << endl; // false
    cout << CheckPermutation("abccceee", "abddddcc") << endl; // false
    cout << CheckPermutation2("abcgdegfg", "gfedcgbga") << endl; // true
    cout << CheckPermutation2("abecdeefg", "gfaedcbae") << endl; // false
    return 0;
}
