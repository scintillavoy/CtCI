#include <iostream>
#include <string>
using namespace std;

string StringCompression(string original) {
    string compressed;
    int count = 1;
    for (int i = 1; i < original.size(); ++i) {
        if (original[i] == original[i-1]) {
            ++count;
        } else {
            compressed += original[i-1];
            compressed += to_string(count);
            count = 1;
        }
    }
    compressed += original.back();
    compressed += to_string(count);
    return compressed.size() < original.size() ? compressed : original;
}

int main() {
    cout << StringCompression("aabccded") << endl;
    cout << StringCompression("aaaaaeeeeeeWWWW") << endl;
    cout << StringCompression("abcdefg") << endl;
    cout << StringCompression("rrrJJJwwEqqeEeeeee") << endl;
    cout << StringCompression("r") << endl;
    return 0;
}
