#include <string>
#include <iostream>
using namespace std;

// Time complexity: O(n)
// Two pointers
string URLify(string str, int len) {
    int last = len;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            last += 2;
        }
    }
    while (--len >= 0) {
        if (str[len] == ' ') {
            str[--last] = '0';
            str[--last] = '2';
            str[--last] = '%';
        } else {
            str[--last] = str[len];
        }
    }
    return str;
}

int main() {
    cout << URLify("Mr John Smith    ", 13) << endl;
    cout << URLify("Scream out for help      ", 19) << endl;
    return 0;
}
