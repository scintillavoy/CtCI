#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

// Review required
// Time complexity: O(V+E)
// Topological sort(DFS)
deque<int> BuildOrder(const vector<vector<int>> &graph) {
  // -1: unvisited, 0: visiting, >0: visited
  vector<int> finish_time(graph.size(), -1);
  deque<int> res;
  stack<int> dfs_stack;
  int time = 0;

  for (int i = 0; i < graph.size(); ++i) {
    if (finish_time[i] == -1) {                 // Found an unvisited node
      finish_time[i] = 0;
      dfs_stack.push(i);
      while (!dfs_stack.empty()) {
        int curr = dfs_stack.top();
        for (const auto &adj : graph[curr]) {
          if (finish_time[adj] == -1) {         // Found an unvisited adjacent
            finish_time[adj] = 0;
            dfs_stack.push(adj);
            break;
          } else if (finish_time[adj] == 0) {   // Caution ! Found a cycle
            return deque<int>();
          }
        }
        if (curr != dfs_stack.top()) continue;  // There is an unvisited adjacent
        finish_time[curr] = ++time;             // All the adjacents are visited
        dfs_stack.pop();
        res.push_front(curr);
      }
    }
  }

  return res;
}

int main() {
  vector<vector<int>> graph1;
  graph1.emplace_back(vector<int>{3});
  graph1.emplace_back(vector<int>{3});
  graph1.emplace_back(vector<int>{});
  graph1.emplace_back(vector<int>{2});
  graph1.emplace_back(vector<int>{});
  graph1.emplace_back(vector<int>{1, 0});
  for (const auto &x : BuildOrder(graph1)) {
    cout << x << ' ';
  }
  return 0;
}
