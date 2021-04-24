#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;

// Time complexity: O(aloga + blogb)
// Sort each array and compare
int SmallestDifference(vector<int> a, vector<int> b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int idx_a = 0, idx_b = 0;
  int min_diff = numeric_limits<int>::max();
  while (idx_a < a.size() && idx_b < b.size()) {
    min_diff = min(min_diff, abs(a[idx_a] - b[idx_b]));
    if (a[idx_a] < b[idx_b]) {
      ++idx_a;
    } else if (a[idx_a] > b[idx_b]) {
      ++idx_b;
    } else {  // min_diff == 0
      break;
    }
  }
  return min_diff;
}

int main() {
  vector<int> a{1, 3, 15, 11, 2};
  vector<int> b{23, 127, 235, 19, 8};
  cout << SmallestDifference(a, b) << endl;
  return 0;
}
