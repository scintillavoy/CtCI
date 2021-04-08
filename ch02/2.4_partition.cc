#include <iostream>
#include <list>
using namespace std;

// Time complexity: O(n)
void Partition(list<int> &li, int x) {
    list<int> right;
    for (auto it = li.begin(); it != li.end(); ) {
        if (*it < x) {
            ++it;
        } else {
            auto temp = it++;
            right.splice(right.end(), li, temp);
        }
    }
    li.splice(li.end(), right);
}

int main() {
    list<int> li = {1, 2, 5, 3, 4, 5, 6, 7, 8, 9, 5, 2};
    Partition(li, 5);
    for (const auto &x : li) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
