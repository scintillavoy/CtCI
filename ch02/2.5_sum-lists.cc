#include <iostream>
#include <list>
using namespace std;

// Time complexity: O(A+B)
// The digits are stored in reverse order
list<int> SumLists(const list<int> &a, const list<int> &b) {
    list<int> sum;
    int carry = 0;
    auto a_it = a.cbegin();
    auto b_it = b.cbegin();
    while (a_it != a.cend() || b_it != b.cend()) {
        int temp = carry;
        if (a_it != a.cend()) {
            temp += *a_it;
            ++a_it;
        }
        if (b_it != b.cend()) {
            temp += *b_it;
            ++b_it;
        }
        carry = temp/10;
        sum.push_back(temp%10);
    }
    if (carry > 0) {
        sum.push_back(carry);
    }
    return sum;
}

int main() {
    list<int> a{1, 9, 9, 9, 1};
    list<int> b{8, 4, 1, 2};
    list<int> sum = SumLists(a, b);
    for (const auto &x : sum) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
