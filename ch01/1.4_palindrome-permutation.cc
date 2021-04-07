#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Review required
// Time complexity: O(n)
// Bit vector
bool PalindromePermutation(string str) {
    int check = 0;
    for (const auto &x : str) {
        if (isalpha(x)) {                               // Check alphabets only
            check ^= 1 << tolower(x)-'a';
        }
    }
    return check == 0 || (check & (check-1)) == 0;      // Caution !
}

int main() {
    cout << PalindromePermutation("Tact Coa") << endl;  // true
    cout << PalindromePermutation("T1 ct C1a") << endl; // true
    cout << PalindromePermutation("Tact oA") << endl;   // false
    cout << PalindromePermutation("aaabbccc") << endl;  // false
    return 0;
}
