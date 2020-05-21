#include <vector>
#include <iostream>
#include <queue>

using namespace std;

std::vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
  int num_nodes = n;
  if (n == 1) {
    return {0};
  }
  std::vector<int> degrees(n, 0);
  std::vector<vector<int>> adjlist(n);
  // calculate degrees
  for (auto edge: edges) {
    degrees[edge[0]]++;
    degrees[edge[1]]++;
    adjlist[edge[0]].push_back(edge[1]);
    adjlist[edge[1]].push_back(edge[0]);
  }

  std::queue<int> q;
  
  while (num_nodes > 2) {
    for (auto i = 0; i < n; ++i) {
      // push degree 1 nodes
      if (degrees[i] == 1) {
        q.push(i);
        degrees[i] = -1;
      }
    }
    
    while (!q.empty()) {
       auto t = q.front();
       q.pop();
       num_nodes--;
       for (auto n : adjlist[t]) {
         degrees[n]--;
       }
    };
  }

  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (degrees[i] == 1 || degrees[i] == 0)
      ans.push_back(i);
  }
  return ans;
}

int main() {
  // std::vector<vector<int>> edges = {
          // {0, 3}, 
          // {1, 3},
          //  {2, 3},
          //   {4, 3},
          //    {5, 4}};
  std::vector<vector<int>> edges = {{1,0}, {1,2}, {1,3}};
  auto res = findMinHeightTrees(4, edges);
  for (auto val: res) {
    cout<<"  "<<val;
  }
}