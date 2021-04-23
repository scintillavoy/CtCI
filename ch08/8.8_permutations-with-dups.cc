#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Review required
void PermutationsWithDups(vector<int> &count, string &res, const int len) {
  if (res.size() == len) {
    cout << res << endl;
  } else {
    for (int i = 0; i < 26; ++i) {
      if (count[i] > 0) {
        --count[i];
        res.push_back(i + 'a');
        PermutationsWithDups(count, res, len);
        res.pop_back();
        ++count[i];
      }
    }
  }
}

void PermutationsWithDups(const string &str) {
  vector<int> count(26, 0);
  for (const auto &x : str) {
    ++count[tolower(x) - 'a'];
  }
  string res;
  PermutationsWithDups(count, res, str.size());
}

int main() {
  string str1("aabc");
  PermutationsWithDups(str1);
  return 0;
}
