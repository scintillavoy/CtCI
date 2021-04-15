#include <iostream>
using namespace std;

// Time complexity: O(n)
// Memoization
int TripleStep(int n) {
  int steps[3] = {1, 2, 3};
  if (n < 0) {
    return 0;
  } else if (n == 0) {
    return 1;
  } else if (n <= 3) {
    return steps[n-1];
  }

  while (n > 3) {
    int temp = steps[0] + steps[1] + steps[2];
    steps[0] = steps[1];
    steps[1] = steps[2];
    steps[2] = temp;
    --n;
  }

  return steps[2];
}

int main() {
  for (int i = 0; i < 38; ++i) {  // Consider the overflow
    cout << TripleStep(i) << endl;
  }
  return 0;
}
