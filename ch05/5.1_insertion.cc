#include <bitset>
#include <iostream>
using namespace std;

int Insertion(int N, int M, int i, int j) {
  int mask = (~0 << (j+1)) | ((1 << i) - 1);
  N = N & mask;
  M = M << i;
  return N | M;
}

int main() {
  int num1 = 0b1101111101011101;
  int num2 = 0b11001;
  cout << bitset<32>(Insertion(num1, num2, 3, 9)) << endl;
  cout << bitset<32>(Insertion(num1, num2, 4, 8)) << endl;
  cout << bitset<32>(Insertion(num1, num2, 4, 9)) << endl;
  return 0;
}
