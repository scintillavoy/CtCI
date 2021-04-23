#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void PaintFill(vector<vector<int>> &screen, pair<int, int> pos, int new_color) {
  if (pos.first < 0 || pos.first >= screen.size() ||
      pos.second < 0 || pos.second >= screen[0].size()) {
    return;
  }
  int old_color = screen[pos.first][pos.second];
  queue<pair<int, int>> bfs;
  bfs.push(pos);
  while (!bfs.empty()) {
    pair<int, int> curr = bfs.front(); bfs.pop();
    if (screen[curr.first][curr.second] != old_color) {
      continue;
    }
    screen[curr.first][curr.second] = new_color;
    if (curr.first+1 < screen.size()) {
      bfs.push(make_pair(curr.first+1, curr.second));
    }
    if (curr.second+1 < screen[0].size()) {
      bfs.push(make_pair(curr.first, curr.second+1));
    }
    if (curr.first-1 >= 0) {
      bfs.push(make_pair(curr.first-1, curr.second));
    }
    if (curr.second-1 >= 0) {
      bfs.push(make_pair(curr.first, curr.second-1));
    }
  }
}

int main() {
  vector<vector<int>> screen{{1,2,3,4,5,6,7,8,9},
                             {1,2,3,4,5,6,7,8,9},
                             {1,2,0,4,5,0,7,8,9},
                             {1,2,3,0,0,6,7,8,9},
                             {1,0,3,0,5,6,0,8,9},
                             {1,2,0,0,0,0,7,8,9},
                             {1,2,0,0,5,6,0,8,9},
                             {1,0,3,0,5,0,7,8,9}};
  PaintFill(screen, make_pair(5, 3), 7);
  for (const auto &row : screen) {
    for (const auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
