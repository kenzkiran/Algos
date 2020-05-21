// Given an integer array arr and an integer k, modify the array by repeating it k times.

// For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

// Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

// As the answer can be very large, return the answer modulo 10^9 + 7.
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
 long Mod = 1000000000 + 7;

int kConcatenationMaxSum(vector<int>& arr, int k) {
 long best = std::numeric_limits<int>::min();
 long running_sum = 0;
 for (auto j = 0; j < k; ++j) {
   for (auto i = 0; i < arr.size(); ++i) {
     running_sum = std::max(0L, running_sum + arr[i]);
     best = std::max(best, running_sum);
   }
 }
 return best % Mod; 
}


int kConcatenationMaxSum2(vector<int>& arr, int k) {
  long forward_best = 0;
  long reverse_best = 0;
  long sum = 0;
  for (auto i = 0; i < arr.size(); ++i) {
    sum += arr[i];
    forward_best = std::max(0l, forward_best + arr[i]);
    reverse_best = std::max(0l, reverse_best + arr[arr.size() - 1 - i]);
  }

  long max = 0;
  if (!(sum > 0)) {
    max = std::max(forward_best + reverse_best, std::max(forward_best, reverse_best));
    max = std::max(0l, max);
  } else {
    max = forward_best + reverse_best + std::max(forward_best, reverse_best) +  (k - 3) * sum;
  }
  return max % Mod;
}

int main() {
    std::vector<int> in{-1,5,-7,2,-1,0,7,6,2,4};
    std::vector<int> other{1, 2, 1};
    //cout<<kConcatenationMaxSum(in ,5);
    kConcatenationMaxSum2(other, 5);
}