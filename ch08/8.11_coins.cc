#include <iostream>
#include <vector>
using namespace std;

// Review required
// DP
int Coins(int n) {
  vector<int> coins{25, 10, 5, 1};
  vector<int> memo(n+1, 0);
  memo[0] = 1;
  for (const auto &coin : coins) {
    for (int i = coin; i < memo.size(); ++i) {
      memo[i] += memo[i-coin];
    }
  }
  return memo[n];
}

int main() {
  for (int i = 0; i < 50; ++i) {
    cout << Coins(i) << endl;
  }
  return 0;
}
