#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Review required
// Time complexity: O(b), where num consists of b bits
int FlipBitToWin(int num) {
  if (~num == 0) {              // Caution ! num consists of all 1s.
    return sizeof(int) * 8;
  }
  int max_length = 1;
  int prev_length = 0;
  int curr_length = 0;
  while (num > 0) {
    if (num & 1) {
      max_length = max(max_length, curr_length);
      ++curr_length;
    } else {
      max_length = max(max_length, curr_length + 1 + prev_length);
      prev_length = curr_length;
      curr_length = 0;
    }
    num >>= 1;
  }
  max_length = max(max_length, curr_length + 1 + prev_length);
  return max_length;
}

int main() {
  vector<int> nums{0b11011111010011111,
                   0b110001,
                   0b111111,
                   0b110111,
                   0b0,
                   0b10,
                   -1};
  for (const auto &num : nums) {
    cout << FlipBitToWin(num) << endl;
  }
  return 0;
}
