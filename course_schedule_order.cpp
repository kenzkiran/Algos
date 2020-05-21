// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  // build incoming order and adj list;
  std::vector<int> incoming_order(numCourses, 0);
  std::vector<std::vector<int>> adjlist(numCourses);
  for (auto& edge: prerequisites) {
    incoming_order[edge[0]]++;
    adjlist[edge[1]].push_back(edge[0]);
  }

  // Collect all '0' incomings
  std:queue<int> q;
  for (auto i = 0; i < numCourses; ++i) {
    if (incoming_order[i] == 0) {
      q.push(i);
    }
  }
  std::vector<int> res;
  int count = 0;
  while (!q.empty()) {
    auto node = q.front();
    q.pop();
    count++;
    res.push_back(node);
    for (auto n: adjlist[node]) {
      incoming_order[n]--;
      if (incoming_order[n] == 0) {
        q.push(n);
      }
    }
  }

  if (count != numCourses) {
    return {};
  }
  return res;
}