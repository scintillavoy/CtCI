#include <iostream>
#include <string>
using namespace std;

void Parens(int n, int opened, string &res) {
  if (n == 0 && opened == 0) {
    cout << res << endl;
    return;
  }
  if (n > 0) {
    res.push_back('(');
    Parens(n-1, opened+1, res);
    res.pop_back();
  }
  if (opened > 0) {
    res.push_back(')');
    Parens(n, opened-1, res);
    res.pop_back();
  }
}

void Parens(int n) {
  string res;
  Parens(n, 0, res);
}

int main() {
  // Parens(0);
  // Parens(1);
  // Parens(2);
  Parens(3);
  // Parens(7);
  return 0;
}
