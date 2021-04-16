#include <iostream>
#include <stack>
using namespace std;

// Time complexity: O(2^n)
void TowersOfHanoi(stack<int> &from, stack<int> &to, stack<int> &other, int i) {
  if (i <= 0) {
    return;
  }
  TowersOfHanoi(from, other, to, i-1);
  to.push(from.top()); from.pop();
  TowersOfHanoi(other, to, from, i-1);
}

void TowersOfHanoi(stack<int> &from, stack<int> &to) {
  stack<int> other;
  TowersOfHanoi(from, to, other, from.size());
}

int main() {
  stack<int> tower, tower2;
  for (int i = 5; i > 0; --i) {
    tower.push(i);
  }
  
  TowersOfHanoi(tower, tower2);

  cout << "tower2:";
  while (!tower2.empty()) {
    cout << ' ' << tower2.top();
    tower2.pop();
  }
  cout << endl;
  return 0;
}
