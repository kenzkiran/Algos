// You are installing a billboard and want it to have the largest height.  
// The billboard will have two steel supports, one on each side.  Each steel support must be an equal height.
// You have a collection of rods which can be welded together.  
// For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.
// Return the largest possible height of your billboard installation.  
// If you cannot support the billboard, return 0.

#include "common.h"

#include <iostream>
#include <vector>

using namespace std;


int SumVector(const std::vector<int>& in) {
  int value = 0;
  for (auto i = 0; i < in.size(); ++i) {
    value += in[i];
  }
  return value;
}


struct Sets {
  std::vector<int> left;
  std::vector<int> right;
  bool IsEqual() {
    return SumVector(left) == SumVector(right);
  };
  int LeftHeight() {
    return SumVector(left);
  }
  int RightHeight() {
    return SumVector(right);
  }
  size_t totalSize() {return left.size() + right.size(); }
  void Dump() {
    DumpVector(left);
    DumpVector(right);
  }
};

class Solution {
public:
    int max = 0;
    std::vector<Sets> GetSets(std::vector<int>& in) {
      if (in.size() == 2) {
        Sets s;
        s.left.push_back(in[0]);
        s.right.push_back(in[1]);
        std::vector<Sets> sets;
        sets.push_back(s);
        return sets;
      }
      std::vector<Sets> new_sets;
      for (auto i = 0 ; i < in.size(); ++i) {
       
      }
      return new_sets;
    }
    int tallestBillboard(vector<int>& rods) {
      int max = 0;
      auto sets = GetSets(rods);
      for (auto& s: sets) {
        if (s.IsEqual()) {
          max = std::max(max, s.LeftHeight());
        }
      }
      return max;
    }
};


int main() {
  std::vector<int> rods = {1,2,3};
  Solution s;
  auto sets = s.GetSets(rods);
  for (auto i = 0; i < sets.size(); ++i) {
    // cout<<"Ravi Set : "<<i<<" Size: " <<sets[i].totalSize()<<endl;
    sets[i].Dump();
    cout<<"------------"<<endl;
  }
  
}