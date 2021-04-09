#include <iostream>
#include <string>
using namespace std;

// Review required
// Time complexity: O(n) if string::find runs in O(A+B) time
bool StringRotation(string s1, string s2) {
  if (s1.length() != s2.length() || s1.length() <= 0) {
    return false;
  }
  s1 += s1;
  return s1.find(s2) != string::npos;
}

int main() {
  cout << StringRotation("waterbottle", "erbottlewat") << endl;
  cout << StringRotation("ababccabdb", "ccabdbabab") << endl;
  cout << StringRotation("waterbottle", "erbkttlewat") << endl;    
  return 0;
}
