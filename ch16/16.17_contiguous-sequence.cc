#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time complexity: O(n)
int ContiguousSequence(const vector<int> &vec) {
  int max_sum = 0;
  int sum = 0;
  for (const auto &x : vec) {
    sum += x;
    sum = max(sum, 0);
    max_sum = max(max_sum, sum);
  }
  return max_sum;
}

int main() {
  cout << ContiguousSequence(vector<int>{2, -8, 3, -2, 4, -10}) << endl;
  return 0;
}
