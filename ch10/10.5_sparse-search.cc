#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time complexity: O(n)
// Binary search
// Increase mid until it finds a non-empty string
int SparseSearch(const vector<string> &strings, const string &target) {
  int low = 0;
  int high = strings.size()-1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int mid_old = mid;
    while (mid <= high && strings[mid] == "") {
      ++mid;
    }
    if (mid == high + 1) {
      high = mid_old - 1;
      continue;
    }
    if (strings[mid] < target) {
      low = mid + 1;
    } else if (strings[mid] > target) {
      high = mid_old - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  vector<string> strings{"at", "", "", "", "ball",
                         "", "", "car", "", "",
                         "dad", "", ""};
  cout << SparseSearch(strings, "at") << endl;
  cout << SparseSearch(strings, "ball") << endl;
  cout << SparseSearch(strings, "car") << endl;
  cout << SparseSearch(strings, "dad") << endl;
  cout << SparseSearch(strings, "star") << endl;
  cout << SparseSearch(strings, "") << endl;
  return 0;
}
