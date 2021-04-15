#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Time complexity: O(row*col)
void RobotInAGrid(vector<vector<int>> grid) {
  if (grid.empty()) {
    cout << "No way." << endl;
  }

  // Find path
  grid[0][0] = 1;
  for (int i = 1; i < grid.size(); ++i) {
    if (grid[i-1][0] == 1 && grid[i][0] != -1) {
      grid[i][0] = 1;
    }
    if (grid[0][i-1] == 1 && grid[0][i] != -1) {
      grid[0][i] = 1;
    }
  }
  for (int i = 1; i < grid.size(); ++i) {
    for (int j = 1; j < grid[0].size(); ++j) {
      if ((grid[i-1][j] == 1 || grid[i][j-1] == 1) && grid[i][j] != -1) {
        grid[i][j] = 1;
      }
    }
  }

  // Reconstruct path backwards
  int row = grid.size()-1;
  int col = grid[0].size()-1;
  if (grid[row][col] != 1) {
    cout << "No way." << endl;
    return;
  }
  deque<char> path;
  while (row != 0 || col != 0) {
    if (row > 0 && grid[row-1][col] == 1) {
      path.push_front('d');
      --row;
    } else if (col > 0 && grid[row][col-1] == 1) {
      path.push_front('r');
      --col;
    }
  }
  cout << "Path: ";
  for (const auto &x : path) {
    cout << x;
  }
  cout << endl;
}

int main() {
  vector<vector<int>> grid{{ 0, 0, 0, 0, 0, 0,-1, 0},
                           { 0, 0,-1,-1, 0,-1, 0, 0},
                           { 0,-1, 0, 0, 0,-1, 0, 0},
                           { 0,-1, 0, 0, 0, 0, 0, 0},
                           { 0, 0, 0,-1, 0,-1,-1, 0},
                           {-1, 0,-1, 0, 0, 0,-1, 0},
                           { 0, 0, 0, 0,-1, 0, 0, 0},
                           { 0, 0,-1, 0, 0,-1, 0,-1},
                           { 0, 0,-1, 0, 0, 0, 0, 0}};
  RobotInAGrid(grid);
  return 0;
}
