#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Review required
// Time complexity: O(V+E)
// BFS
bool RouteBetweenNodes(const vector<vector<int>> &graph, int start, int end) {
  if (start == end) return true;
  
  vector<int> state(graph.size());
  queue<int> bfs_queue;

  state[start] = 1;
  bfs_queue.push(start);
  while (!bfs_queue.empty()) {
    int curr = bfs_queue.front(); bfs_queue.pop();
    for (const auto adj : graph[curr]) {
      if (state[adj] == 1) continue;
      if (adj == end) return true;
      state[adj] = 1;
      bfs_queue.push(adj);
    }
  }
  return false;
}

int main() {
  vector<vector<int>> graph1;
  graph1.emplace_back(vector<int>{1,4,5});
  graph1.emplace_back(vector<int>{3,4});
  graph1.emplace_back(vector<int>{1});
  graph1.emplace_back(vector<int>{2,4});
  graph1.emplace_back(vector<int>{});
  graph1.emplace_back(vector<int>{});
  for (int i = 0; i < graph1.size(); ++i) {
    for (int j = 0; j < graph1.size(); ++j) {
      cout << RouteBetweenNodes(graph1, i, j) << ' ';
    }
    cout << endl;
  }
  return 0;
}
