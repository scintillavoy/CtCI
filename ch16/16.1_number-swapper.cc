#include <iostream>
using namespace std;

// Review required
// Time complexity: O(1)
// XOR works for more data types than just integers
void NumberSwapper(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

int main() {
  int a = 326;
  int b = 591;
  NumberSwapper(a, b);
  cout << a << ' ' << b << endl;
  return 0;
}
