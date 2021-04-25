#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// Time complexity: O(n)
pair<int, int> SubSort(vector<int> &vec) {
  int min_idx = -1;
  int local_min = vec[0];
  int local_max = vec[0];
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i] < vec[i-1]) {
      local_min = vec[i];
      local_max = max(local_max, vec[i-1]);
    }
  }
  if (local_min == local_max) { // The array is already sorted
    return make_pair(-1, -1);
  }
  int m = 0;
  while (vec[m] <= local_min) {
    ++m;
  }
  int n = vec.size()-1;
  while (vec[n] >= local_max) {
    --n;
  }
  return make_pair(m, n);
}

int main() {
  // vector<int> vec{1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
  vector<int> vec{1, 2, 4, 7, 10, 11, 18, 19};
  auto res = SubSort(vec);
  cout << res.first << ' ' << res.second << endl;
  return 0;
}