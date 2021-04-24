#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(logn)
// Find the size by inspecting elements at 1, 2, 4, 8, ...
// and do binary search.
int SortedSearchNoSize(const vector<int> &listy, int target) {
  int high = 1;
  while (high < listy.size()) {   // listy[high] != -1
    if (listy[high] > target) {
      break;
    } else if (listy[high] == target) {
      return high;
    }
    high <<= 1;
  }
  int low = high >> 1;
  while (low <= high) {
    int mid = low + (high-low)/2;
    if (mid >= listy.size() || listy[mid] > target) { // listy[mid] == -1 || listy[mid] > target
      high = mid - 1;
    } else if (listy[mid] < target) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  vector<int> listy{2, 3, 5, 7, 9,
                    11, 16, 18, 20, 30,
                    40, 44, 47, 52, 57,
                    59, 61, 62, 65, 67};
  cout << SortedSearchNoSize(listy, 6) << endl;
  cout << SortedSearchNoSize(listy, 7) << endl;
  cout << SortedSearchNoSize(listy, 47) << endl;
  cout << SortedSearchNoSize(listy, 59) << endl;
  cout << SortedSearchNoSize(listy, 67) << endl;
  cout << SortedSearchNoSize(listy, 77) << endl;
  return 0;
}
