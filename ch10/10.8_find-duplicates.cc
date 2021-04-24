#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

void FindDuplicates(const vector<int> &vec) {
  bitset<32000> check;
  for (const auto &num : vec) {
    if (check[num-1] == 1) {
      cout << num << endl;
    } else {
      check[num-1] = 1;
    }
  }
}

int main() {
  vector<int> vec{7, 1, 8, 2, 5,
                  2, 88, 332, 12, 1,
                  39, 201, 302, 444, 2};
  FindDuplicates(vec);
  return 0;
}
