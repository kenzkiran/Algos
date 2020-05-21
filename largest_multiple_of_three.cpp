// Given an integer array of digits, return the largest multiple of three that
// can be formed by concatenating some of the given digits in any order. Since
// the answer may not fit in an integer data type, return the answer as a
// string. If there is no answer return an empty string.

#include <algorithm>
#include <iostream>
#include <vector>

#include "common.h"

using namespace std;

long current_max_dividend = 0;
long current_max_value = 0;
bool did_evaluate = false;

void EvaluteDiv3(std::vector<int>& input) {
  long res = 0;
  for (auto i = 0; i <input.size(); ++i) {
    res = (res * 10) + input[i];
  }

  if (res % 3 == 0) {
    did_evaluate = true;
    long dividend = res / 3;
    if (dividend > current_max_dividend) {
      current_max_dividend = dividend;
      current_max_value = res;
    }
  }
}

std::vector<std::vector<int>> AllPossibleCombinations(vector<int>& digits) {
  std::vector<std::vector<int>> res;
  if (digits.size() == 2) {
    std::vector<int> c1{digits[1], digits[0]};
    EvaluteDiv3(digits);
    EvaluteDiv3(c1);
    res.push_back(digits);
    res.push_back(c1);
    return res;
  }

  for (auto i = 0; i < digits.size(); ++i) {
    vector<int> copy = digits;
    int current = digits[i];
    auto iter = copy.begin();
    std::advance(iter, i);
    copy.erase(iter);

    auto sub_res = AllPossibleCombinations(copy);
    for (auto j = 0; j < sub_res.size(); ++j) {
      sub_res[j].push_back(current);
      res.push_back(std::move(sub_res[j]));
    }
  }

  for (auto i = 0; i < res.size(); ++i) {
    EvaluteDiv3(res[i]);
  }
  return res;
} 

string largestMultipleOfThree(vector<int> &digits) {
  if (digits.size() == 1) {
    if (digits[0] % 3 == 0) {
      return std::to_string(digits[0]);
    }
    return "";
  }
  AllPossibleCombinations(digits);
  if (current_max_value) {
    return std::to_string(current_max_value);
  } else {
    if (did_evaluate) {
      return "0";
    }
    else {
      return "";
    }
  }
}

int main() {
  std::vector<int> arr = {7,8,7,2,1,2,6,6,9,2};

  // std::sort(arr.begin(), arr.end(), greater <>());
  // std::sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });

  auto res = AllPossibleCombinations(arr);
  for (auto i = 0; i < res.size(); ++i) {
    // DumpVector(res[i]);
  }

  cout<<"Ravi  Max value "<<current_max_value;
  
}