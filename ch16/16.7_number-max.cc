#include <iostream>
using namespace std;

// Review required
int NumberMax(const int &a, const int &b) {
  int sign_of_a = (a >> (sizeof(int)*8-1)) + 1; // 1 if +, 0 if -
  int sign_of_b = (b >> (sizeof(int)*8-1)) + 1; // 1 if +, 0 if -
  int sign_xor = sign_of_a ^ sign_of_b; // 1 if signs of a and b are different
  int sign_of_diff = ((a-b) >> (sizeof(int)*8-1)) + 1; // 1 if a >= b, 0 if a < b
  return sign_xor * (sign_of_a * a + sign_of_b * b) +
         (1-sign_xor) * (sign_of_diff * a + (1-sign_of_diff) * b);
}

int main() {
  cout << NumberMax(32, 48) << endl;
  cout << NumberMax(32, 1) << endl;
  cout << NumberMax(-2, 8) << endl;
  cout << NumberMax(3, -5) << endl;
  cout << NumberMax(-21, -63) << endl;
  cout << NumberMax(2147000000, -2146000000) << endl;
  return 0;
}
