#include <iostream>
#include <list>
#include <vector>
#include "common.h"
using namespace std;


void RemoveDuplicates(std::list<int>& in) {
  std::map<int, bool> count_map;
  for(auto iter = in.begin(); iter != in.end(); ) {
    if (count_map.count(*iter)) {
      iter = in.erase(iter);
    } else {
      count_map[*iter] = true;
      ++iter;
    }
  }
}

void RemoveDuplicatesRunner(std::list<int>& in) {
  for (auto iter = in.begin(); iter != in.end();) {
    auto cur_val = *iter;
    auto runner_start = iter;
    ++runner_start;
    while(runner_start != in.end()) {
      if (*runner_start == cur_val) {
        runner_start = in.erase(runner_start);
      } else {
        ++runner_start;
      }
    }
    iter++;
  } 
}

void removeEven(std::vector<int>& in) {
  for (auto iter = in.begin(); iter != in.end();) {
    if ( *iter % 2 == 0 )  {
      iter = in.erase(iter);
    } else {
      ++iter;
    }
  }
}




int main() {
  std::vector<int> tvec{1, 2, 3, 10, 12, 13, 15, 16, 17, 18};
  std::list<int> alist;
  alist.push_back(15);
  alist.push_back(8);
  alist.push_back(9);
  alist.push_back(9);
  alist.push_back(10);
  alist.push_back(11);
  alist.push_back(8);
  alist.push_back(8);
  alist.push_back(9);

  RemoveDuplicatesRunner(alist);
  DumpList(alist, " -> ");
  DumpVector(tvec, ", ");
  removeEven(tvec);
  DumpVector(tvec, " ");
}