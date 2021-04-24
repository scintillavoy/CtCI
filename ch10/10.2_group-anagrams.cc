#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

// Another approach: sort each string and group them using a hash table.
// unordered_multimap would be an appropriate data structure.
void GroupAnagrams(vector<string> &strings) {
  sort(strings.begin(), strings.end(), [](const string &a, const string &b) {
    vector<int> count_a(26, 0);
    vector<int> count_b(26, 0);
    for (const auto &x : a) {
      ++count_a[tolower(x) - 'a'];
    }
    for (const auto &x : b) {
      ++count_b[tolower(x) - 'a'];
    }
    return count_a < count_b;
  });
}

int main() {
  vector<string> strings{"aabbc",
                         "bbccc",
                         "bbcaa",
                         "aazz",
                         "yxyy",
                         "cbcbc",
                         "cabab",
                         "zaza",
                         "yyyx"};
  GroupAnagrams(strings);
  for (const auto &x : strings) {
    cout << x << endl;
  }
  return 0;
}
