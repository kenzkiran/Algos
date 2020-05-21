// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int longestValidParentheses(std::string& s) {
  if (s.length() < 2) {
    return 0;
  }
  std::vector<int> current_set;
  bool is_streak_started = false;
  int longest = 0;
  int streak_len = 0;
  int stack_len = 0;
  for(auto i = 0; i < s.length(); ++i) {
    auto letter = s[i];
    
    if (letter == '(') {
      if (!is_streak_started) {
        is_streak_started = true;
      }
      current_set.push_back(1);
    }
    
    if (letter == ')') { 
      // if there was a current set
      if (current_set.size()) {
        current_set.pop_back();
        stack_len += 2;
        if (current_set.empty() && is_streak_started) {
          streak_len += stack_len;
          stack_len = 0;
        }
      } else {
        if(is_streak_started && current_set.empty()) {
          // implies streak ended
          is_streak_started = false;
          longest = std::max(streak_len, longest);
          current_set.clear();
          streak_len = 0;
        }
      }
    }
  }

  if (current_set.size() && is_streak_started) {
    streak_len = std::max(streak_len, stack_len);
  }
  longest = std::max(streak_len, longest);
  return longest;
}


int main(int argc, char *argv[]) {
  std::string in = "()";
  if (argc > 1) {
    in = std::string(argv[1]);
  }
  cout<<"Ravi Getting for : "<<in<<endl;
  cout<<"Ravi longest "<<longestValidParentheses(in)<<endl;
  
}