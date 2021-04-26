#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <numeric>
using namespace std;

// Time complexity: O(A+B)
pair<int, int> SumSwap(const vector<int> &A, const vector<int> &B) {
  int sum_A = accumulate(A.cbegin(), A.cend(), 0);
  int sum_B = accumulate(B.cbegin(), B.cend(), 0);
  int sum_diff = sum_A - sum_B;
  if (sum_diff % 2 != 0) {
    return make_pair(-1, -1);
  }
  sum_diff /= 2;
  unordered_set<int> set;
  for (const auto &x : A) {
    set.insert(x - sum_diff);
  }
  for (const auto &x : B) {
    if (set.count(x) > 0) {
      return make_pair(x + sum_diff, x);
    }
  }
  return make_pair(-1, -1);
}

int main() {
  auto res = SumSwap({4, 1, 2, 1, 1, 2}, {3, 6, 3, 3});
  cout << res.first << ' ' << res.second << endl;
  return 0;
}
