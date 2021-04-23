#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Review required
// Time complexity: O(n^2 * n!)
// Recursion with restoring the previous state
void PermutationsWithoutDups(string &str, int from = 0) {
  if (str.empty()) {
    return;
  }
  if (str.size() == from) {
    cout << str << endl;
  } else {
    for (int i = from; i < str.size(); ++i) {
      swap(str[from], str[i]);
      PermutationsWithoutDups(str, from + 1);
      swap(str[from], str[i]);
    }
  }
}

int main() {
  string str1("abcd");
  PermutationsWithoutDups(str1);
  return 0;
}
