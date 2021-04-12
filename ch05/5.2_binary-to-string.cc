#include <iostream>
#include <string>
using namespace std;

// Alternative approach: multiplying num by 2 and compare with 1
string BinaryToString(double num) {
  string res(".");
  double sub = 0.5;
  while (num > 0) {
    if (res.size() > 32) {
      return "ERROR";
    }
    if (num >= sub) {
      res.push_back('1');
      num -= sub;
    } else {
      res.push_back('0');
    }
    sub /= 2;
  }
  return res;
}

int main() {
  cout << BinaryToString((double)0.5) << endl;
  cout << BinaryToString((double)0.625) << endl;
  cout << BinaryToString((double)0.75) << endl;
  cout << BinaryToString((double)0.875) << endl;
  cout << BinaryToString((double)0.1) << endl;
  cout << BinaryToString((double)0.123) << endl;
  cout << BinaryToString((double)0.12) << endl;
  cout << BinaryToString((double)0.13) << endl;
  return 0;
}
