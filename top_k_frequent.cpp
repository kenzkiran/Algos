// Given a non-empty array of integers, return the k most frequent elements.
#include <iostream>
#include <queue>
#include <map>

#include "common.h"

using namespace std;


struct Freq {
  Freq(int n = -1, int c = -1) : number(n), freq(c) {}
  int number;
  int freq;
};
vector<int> topKFrequent(vector<int> &nums, int k) {
  std::map<int, int> frequency;
  for (auto i = 0; i < nums.size(); ++i) {
    if (frequency.count(nums[i])) {
      frequency[nums[i]]++;
    } else {
      frequency[nums[i]] = 1;
    }
  }
  
  auto cmp = [](auto& l, auto& r) {
    return l.freq > r.freq;
  };
  std::priority_queue<Freq, std::vector<Freq>, decltype(cmp)> pq(cmp);
  for (auto& [key, value] : frequency) {
    pq.push(Freq(key, value));
  }

  while(!pq.empty() && pq.size() > k) {
    auto top = pq.top();
    pq.pop();
  }

  std::vector<int> res;
  while(!pq.empty()) {
    auto top = pq.top();
    res.push_back(top.number);
    pq.pop();
  }

  return res;
}


int main() {
  // auto cmp = [](auto left, auto right) {
  //   return left > right;
  // };
  // std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
  // for (int i = 5; i >= 0 ; --i) {
  //   pq.push(i);
  // }
  // while(!pq.empty()) {
  //   cout<<pq.top()<<endl;
  //   pq.pop();
  // }

  std::vector<int> in{1,1,1,2,2,3,3,3,3};
  DumpVector(topKFrequent(in, 2));
}