#include <iostream>
#include <list>
#include <unordered_set>
#include <iterator>
using namespace std;

// Time complexity: O(n)
// Hash table, one pass
void RemoveDups(list<int> &li) {
    unordered_set<int> check;
    for (auto it = li.begin(); it != li.end(); ) {
        if (check.find(*it) == check.end()) {
            check.insert(*it);
            ++it;
        } else {
            it = li.erase(it);
        }
    }
}

// Time complexity: O(n^2)
// Two pointers
void RemoveDups2(list<int> &li) {
    for (auto curr = li.begin(); curr != li.end(); ++curr) {
        for (auto runner = next(curr); runner != li.end(); ) {
            if (*curr != *runner) {
                ++runner;
            } else {
                runner = li.erase(runner);
            }
        }
    }
}

int main() {
    list<int> li = {1, 2, 5, 3, 4, 5, 6, 7, 8, 9, 5, 2};
    RemoveDups2(li);
    for (const auto x : li) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
