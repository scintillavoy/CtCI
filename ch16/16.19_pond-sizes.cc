#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Review required
// Time complexity: O(WH)
// BFS
vector<int> PondSizes(vector<vector<int>> land) {
  vector<int> res;
  for (int row = 0; row < land.size(); ++row) {
    for (int col = 0; col < land[0].size(); ++col) {
      if (land[row][col] != 0) continue;
      queue<pair<int, int>> bfs;
      bfs.push({row, col});
      int pond_size = 0;
      while (!bfs.empty()) {
        pair<int, int> idx = bfs.front(); bfs.pop();
        if (idx.first < 0 || idx.first >= land.size() ||
            idx.second < 0 || idx.second >= land[0].size() ||
            land[idx.first][idx.second] != 0) {
          continue;
        }
        land[idx.first][idx.second] = -1;
        ++pond_size;
        for (int dr = -1; dr <= 1; ++dr) {
          for (int dc = -1; dc <= 1; ++dc) {
            bfs.push({idx.first+dr, idx.second+dc});  // 8-way
          }
        }
      }
      res.push_back(pond_size);
    }
  }
  return res;
}

int main() {
  vector<vector<int>> land1{{0,2,1,0},
                            {0,1,0,1},
                            {1,1,0,1},
                            {0,1,0,1}};
  for (const auto &x : PondSizes(land1)) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
