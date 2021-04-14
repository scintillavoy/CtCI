#include <iostream>
using namespace std;

int Conversion(int A, int B) {
  int count = 0;
  int XOR = A ^ B;
  for (int XOR = A ^ B; XOR > 0; XOR >>= 1) {
    if (XOR & 1) {
      ++count;
    }
  }
  return count;
}

int main() {
  int A = 0b11101;
  int B = 0b01111;
  cout << Conversion(A, B) << endl;
  return 0;
}
