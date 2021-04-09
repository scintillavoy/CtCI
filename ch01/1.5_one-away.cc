#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Review required
// Time complexity: O(A+B)
// Count characters
// There are other solutions without counting
bool OneAway(string a, string b) {
  int count[26] = {0,};
  for (const auto &x : a) {
    ++count[x - 'a'];
  }
  for (const auto &x : b) {
    --count[x - 'a'];
  }
  int diff = 0;
  for (int i = 0; i < 26; ++i) {
    if (abs(count[i]) >= 2) {
      return false;
    }
    diff += abs(count[i]);
  }
  return diff <= 2;
}

int main() {
  cout << OneAway("pale", "ple") << endl;     // true
  cout << OneAway("pales", "pale") << endl;   // true
  cout << OneAway("pale", "bale") << endl;    // true
  cout << OneAway("pale", "bake") << endl;    // false
  return 0;
}
