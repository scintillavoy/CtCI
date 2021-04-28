#include <iostream>
#include <queue>
using namespace std;

// Review required
// Time complexity: O(nlogk)
// Track the smallest K numbers using max heap
// Expected O(n) time with selection rank algorithm is also possible
void SmallestK(const vector<int> &numbers, int K) {
  if (numbers.size() < K) {
    for (const auto &x : numbers) {
      cout << x << ' ';
    }
    cout << endl;
    return;
  }
  priority_queue<int> max_heap;
  for (int i = 0; i < K; ++i) {
    max_heap.push(numbers[i]);
  }
  for (int i = K; i < numbers.size(); ++i) {
    if (numbers[i] < max_heap.top()) {
      max_heap.pop();
      max_heap.push(numbers[i]);
    }
  }
  while (!max_heap.empty()) {
    cout << max_heap.top() << ' ';
    max_heap.pop();
  }
  cout << endl;
}

int main() {
  SmallestK({7, 19, 2, 123, 582, 391, 234, 61, 233, 21, 88}, 5);
  return 0;
}
