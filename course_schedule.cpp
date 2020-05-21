// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  std::vector<std::vector<int>> adjlist(numCourses);
  std::vector<int> incoming(numCourses, 0);
  for (auto edges: prerequisites) {
    incoming[edges[0]]++;
    adjlist[edges[1]].push_back(edges[0]);
  }

  std::queue<int> q;
  for (auto i = 0; i < numCourses; ++i) {
    if (incoming[i] == 0) {
      q.push(i);
    }
  }
  int count = 0;
  while(!q.empty()) {
    auto n = q.front();
    q.pop();
    count++;
    for (auto adj: adjlist[n]) {
      incoming[adj]--;
      if (incoming[adj] == 0) {
        q.push(adj);
      }
    }
  }

  return count == numCourses;
}

int main() {

}