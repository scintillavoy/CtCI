#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void EightQueens(vector<int> &arranged, vector<unordered_set<int>> &check, int row = 0) {
  if (row == 8) {
    for (auto const &x : arranged) {
      for (int i = 0; i < 8; ++i) {
        if (i == x) {
          cout << "Q ";
        } else {
          cout << ". ";
        }
      }
      cout << endl;
    }
    cout << endl;
    return;
  }
  for (int i = 0; i < 8; ++i) {
    if (check[0].find(i) != check[0].end() ||
        check[1].find(row-i) != check[1].end() ||
        check[2].find(row+i) != check[2].end()) {
      continue;
    }
    check[0].insert(i);
    check[1].insert(row-i);
    check[2].insert(row+i);
    arranged.push_back(i);
    EightQueens(arranged, check, row+1);
    check[0].erase(i);
    check[1].erase(row-i);
    check[2].erase(row+i);
    arranged.pop_back();
  }
}

void EightQueens() {
  vector<int> arranged;
  vector<unordered_set<int>> check;
  check.emplace_back(); // check[0]: check column
  check.emplace_back(); // check[1]: check diagonal to right down
  check.emplace_back(); // check[2]: check diagonal to left down
  EightQueens(arranged, check, 0);
}

// 00 01 02 03 04 05 06 07
// 10 11 12 13 14 15 16 17
// 20 21 22 23 24 25 26 27

int main() {
  EightQueens();
  return 0;
}
