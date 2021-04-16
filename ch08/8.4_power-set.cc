#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(n*2^n)
vector<vector<int>> PowerSet(const vector<int> &s) {
  if (s.empty()) {
    return vector<vector<int>>();
  }
  vector<vector<int>> res(1, vector<int>());
  for (int i = 0; i < s.size(); ++i) {
    int prev_size = res.size();
    for (int j = 0; j < prev_size; ++j) {
      res.push_back(res[j]);
      res.back().push_back(s[i]);
    }
  }
  return res;
}

int main() {
  vector<vector<int>> res = PowerSet(vector<int>{3, 5, 6, 8});
  for (const auto &x : res) {
    for (const auto &y : x) {
      cout << y << ' ';
    }
    cout << endl;
  }
  return 0;
}
