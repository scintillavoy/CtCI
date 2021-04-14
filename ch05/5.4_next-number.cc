#include <iostream>
#include <bitset>
using namespace std;

// Time complexity: O(b), where num consists of b bits
// Arithmetic approach is also possible. Try 2^n-1.
int NextSmallestNumber(int num) {
  int num_of_0 = 0;
  int num_of_1 = 0;
  while (num > 0) {
    if (num & 1) {
      ++num_of_1;
    } else {
      if ((num & 2) != 0) {
        num = num >> 2;
        num = (num << 2) + 1;
        break;
      }
      ++num_of_0;
    }
    num = num >> 1;
  }
  while (num_of_1 > 0) {
    num = (num << 1) + 1;
    --num_of_1;
  }
  while (num_of_0 > 0) {
    num = num << 1;
    --num_of_0;
  }
  return num;
}

int main() {
  int num = 0b111100011111;
  cout << bitset<32>(NextSmallestNumber(num)) << endl;
  return 0;
}

// the next smallest
// left -> right, find '10'
// change '10' to '01'
// (change point) left -> right, count the numbers of 1s and 0s
// set left as 1s and right as 0s
// 111100011111
// 111011111100

// the next largest
// right -> left, find '01'
// change '01' to '10'
// (change point) left -> right, count the numbers of 1s and 0s
// set left as 0s and right as 1s
// 110001111100
// 110010001111

// edge cases
// 11111111
// 00000000
