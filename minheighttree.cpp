// For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

#include <iostream>
#include <vector>
#include <set>
#include "common.h"
using namespace std;

std::vector<set<int>> paths_lengths;

void findAllPaths(vector<vector<int>>& edges, vector<int>& path) {
  auto connection = path.back();
  bool did_add = false;
  for (auto e: edges) {
    int link = -1;
    if (e[0] == connection) {
      link = e[1];
    } else if (e[1] == connection) {
      link = e[0];
    }

    if (link >= 0) {
      auto found = std::find(path.begin(), path.end(), link);
      if (found == path.end()) {
        path.push_back(link);
        did_add = true;
        findAllPaths(edges, path);
        path.pop_back();
      }
    }
  }

  if (!did_add) {
    if (path.size() > 1) {
      paths_lengths[path[0]].insert(path.size());
    }
  }
}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    for (auto i = 0; i < n; ++i)  {
      paths_lengths.push_back(std::set<int>());
      std::vector<int> path;
      path.push_back(i);
      findAllPaths(edges, path);
    }

    std::vector<int> indexes;
    auto min_height = std::numeric_limits<int>::max();
    for (auto i = 0; i < paths_lengths.size(); ++i) {
      auto set_for = paths_lengths[i];
      auto lowest = *set_for.rbegin();
      if (lowest  < min_height) {
        min_height = lowest;
        indexes.clear();
        indexes.push_back(i);
      } else if (lowest == min_height) {
        indexes.push_back(i);
      }
    }
    return indexes;
}

int main() {

  // std::vector<vector<int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
  std::vector<vector<int>> edges = {{0, 1}};
  findMinHeightTrees(2, edges);
  // for (auto i = 0; i < paths_lengths.size(); ++i) {
  //   auto set_for = paths_lengths[i];
  //   for (auto iter = set_for.begin(); iter != set_for.end(); ++iter) {
  //     cout<<"  "<<*iter;
  //   }
  //   cout<<endl;
  // }
}