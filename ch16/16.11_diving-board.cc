#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(K)
vector<int> DivingBoard(int shorter, int longer, int K) {
  if (shorter == longer) {    // Caution !
    return vector<int>{shorter * K};
  }
  vector<int> res;
  for (int i = 0; i <= K; ++i) {
    res.push_back(shorter * (K-i) + longer * i);
  }
  return res;
}

int main() {
  for (const auto &x : DivingBoard(3, 7, 10)) {
    cout << x << ' ';
  }
  cout << endl;
  for (const auto &x : DivingBoard(5, 5, 10)) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
