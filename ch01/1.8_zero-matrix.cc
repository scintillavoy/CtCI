#include <vector>
#include <iostream>
using namespace std;

// Time complexity: O(MN)
// Remember rows and columns to be cleared.
// We can reduce the additional space usage to O(1)
// by using the matrix itself for data storage.
void ZeroMatrix(vector<vector<int>> &mat) {
  vector<bool> row(mat.size(), false);
  vector<bool> col(mat[0].size(), false);
  for (int i = 0; i < mat.size(); ++i) {
    for (int j = 0; j < mat[0].size(); ++j) {
      if (mat[i][j] == 0) {
        row[i] = true;
        col[j] = true;
      }
    }
  }
  for (int i = 0; i < mat.size(); ++i) {
    if (row[i]) {
      for (int j = 0; j < mat[0].size(); ++j) {
        mat[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < mat[0].size(); ++i) {
    if (col[i]) {
      for (int j = 0; j < mat.size(); ++j) {
        mat[j][i] = 0;
      }
    }
  }
}

int main() {
  vector<vector<int>> mat1 = {{1,2,3,4,5},
                              {6,7,0,9,1},
                              {0,2,3,5,2},
                              {8,8,2,3,1},
                              {6,8,3,1,0}};
  ZeroMatrix(mat1);
  for (const auto &row : mat1) {
    for (const auto &x : row) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}
