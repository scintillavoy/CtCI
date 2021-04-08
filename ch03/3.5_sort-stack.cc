#include <iostream>
#include <stack>
using namespace std;

// Review required
// Time complexity: O(n^2)
// Only one additional stack is permitted
// With unlimited additional stacks, quicksort or mergesort is possible
void SortStack(stack<int> &stk) {
    if (stk.empty()) return;
    stack<int> stk2;
    while (!stk.empty()) {
        int temp = stk.top();
        stk.pop();
        // Remember to check if the stack is empty before calling top()
        while (!stk2.empty() && stk2.top() > temp) {    // Caution !
            stk.push(stk2.top());
            stk2.pop();
        }
        stk2.push(temp);
    }
    while (!stk2.empty()) {
        stk.push(stk2.top());
        stk2.pop();
    }
}

int main() {
    stack<int> stk1({8,26,4,1,2});
    stack<int> stk2({876,22365,421});
    SortStack(stk1);
    SortStack(stk2);
    while (!stk1.empty()) {
        cout << stk1.top() << ' ';
        stk1.pop();
    }
    cout << endl;
    while (!stk2.empty()) {
        cout << stk2.top() << ' ';
        stk2.pop();
    }
    cout << endl;
    return 0;
}
