// print all valid pair of parantheses given a set of N.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printAllValidPairs(int num_pairs, std::vector<std::string>& pattern) {
  if ( num_pairs == 1) {
    pattern.push_back("()");
    return;
  }
  std::vector<std::string> sub_pattern;
  printAllValidPairs(num_pairs - 1, sub_pattern);
  bool is_final = false;
  for (auto i = 0 ;i < sub_pattern.size(); ++i) {
    pattern.push_back("(" + sub_pattern[i] + ")");
    pattern.push_back("()" + sub_pattern[i]);
    if (i < (sub_pattern.size() - 1)) {
      pattern.push_back(sub_pattern[i] + "()");
    }
  }
  return;
}

int main() {
  std::vector<std::string> pattern;
  printAllValidPairs(3, pattern);
  for (auto i = 0 ;i < pattern.size(); ++i) {
    cout<<pattern[i]<<endl;
  }
}

