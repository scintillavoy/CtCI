#include <iostream>
#include <forward_list>
using namespace std;

// Review required
// Time complexity: O(n)
// Two pointers: (1) kth to last, (2) last
// There is a solution using recursion
int ReturnKthToLast(const forward_list<int> &li, int k) {
    auto kth = li.cbegin();
    auto runner = li.cbegin();
    for (int i = 0; i < k; ++i) {
        if (runner == li.cend()) return -1;     // return value?
        ++runner;
    }
    while (runner != li.cend()) {
        ++kth;
        ++runner;
    }
    return *kth;
}

int main() {
    forward_list<int> li = {1, 2, 5, 3, 4, 5, 6, 7, 8, 9, 5, 2};
    cout << ReturnKthToLast(li, 5) << endl;
    return 0;
}
