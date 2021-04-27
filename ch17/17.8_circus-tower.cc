#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// Review required
// Time complexity: O(n^2)
// Sorting, recursion, memoization
// O(nlogn) solution exists
int CircusTower(const vector<pair<int, int>> &puppets,
                vector<int> &memo, int top) {
  if (memo[top] != -1) {
    return memo[top];
  }
  int len = 0;
  for (int i = top+1; i < puppets.size(); ++i) {
    if (puppets[top].first < puppets[i].first &&
        puppets[top].second < puppets[i].second) {
      len = max(len, CircusTower(puppets, memo, i));
    }
  }
  memo[top] = len + 1;
  return memo[top];
}

int CircusTower(vector<pair<int, int>> puppets) {
  if (puppets.empty()) {
    return 0;
  }
  sort(puppets.begin(), puppets.end(),
       [](const pair<int, int> &a, const pair<int, int> &b){
         return a.first < b.first;
       });
  vector<int> memo(puppets.size(), -1);
  int max_len = 0;
  for (int i = 0; i < puppets.size(); ++i) {
    max_len = max(max_len, CircusTower(puppets, memo, i));
  }
  return max_len;
}

int main() {
  vector<pair<int, int>> puppets1{{65,100},{70,150},{56,90},
                                  {75,190},{60,95},{68,110}};
  vector<pair<int, int>> puppets2{{65,100},{70,150},{56,90},
                                  {75,190},{60,95},{68,110},
                                  {72,120},{73,140},{75,191}};
  cout << CircusTower(puppets1) << endl;
  cout << CircusTower(puppets2) << endl;
  return 0;
}
