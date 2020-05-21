
class Solution {
public:
    int count = 0;
    bool IsWholeNumber(double val) {
        return (val == static_cast<int>(val));
    }
    long Reverse(long val) {
      long ans = 0;
      while (val > 0) {
        ans = ans * 10 + val % 10;
        val = val / 10;
      }
      return ans;
    }
    bool CheckPalindrome(long val) {
      return val == Reverse(val);
    }
    int superpalindromesInRange(string L, string R) {
       long start = stol(L);
       long end = stol(R);
       for (auto i = start; i <= end; ++i) {
           double root = sqrt(i);
           if (IsWholeNumber(root)) {
               if (CheckPalindrome(static_cast<int>(root)) && CheckPalindrome(i)) {
                   count++;
               }
           }
       }
       return count;
    }
};