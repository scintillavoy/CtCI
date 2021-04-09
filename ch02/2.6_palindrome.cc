#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// Time complexity: O(n)
bool Palindrome(const list<int> &li) {
  if (li.empty()) {
    return true;
  }
  auto front = li.cbegin();
  auto back = --li.cend();
  while (front != back && prev(front) != back) {
    if (*front != *back) {
      return false;
    }
    ++front;
    --back;
  }
  return true;
}

int main() {
  list<int> li1{1, 2, 3, 3, 2, 1};
  list<int> li2{1, 2, 3, 4, 3, 2, 1};
  list<int> li3{1, 1, 3, 3, 4, 3, 1, 1};
  list<int> li4{3, 2, 1, 2, 4};
  cout << Palindrome(li1) << endl;
  cout << Palindrome(li2) << endl;
  cout << Palindrome(li3) << endl;
  cout << Palindrome(li4) << endl;
  return 0;
}
