#include <iostream>
#include <vector>
using namespace std;

// Reivew required
// Time complexity: O(logn)
// Binary search
int MagicIndex(const vector<int> &arr) {
  if (arr.empty()) {
    return -1;
  }
  int low = 0;
  int high = arr.size()-1;
  while (low <= high) {
    int mid = low + ((high - low) / 2);   // Prevent overflow
    if (arr[mid] == mid) {
      return mid;
    } else if (arr[mid] < mid) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  // vector<int> arr{-5, -3, -1, 0, 3, 5, 7, 9};
  vector<int> arr{-5, 1, 3, 5, 6, 7, 9, 13};
  cout << MagicIndex(arr) << endl;
  return 0;
}
