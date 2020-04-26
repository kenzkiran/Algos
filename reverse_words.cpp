// Given an input string, reverse the string word by word.

#include <iostream>
#include <string>
#include <vector>

using namespace std;
std::vector<string> splitter(string s) {
  std::string current;
  std::vector<string> res;
  for (auto i = 0; i < s.length(); ++i) {
    if (s[i] == ' ' || s[i] == '\n' || s[i] == '\0') {
      if (current.length()) {
        res.push_back(std::move(current));
      }
    } else {
      current.push_back(s[i]);
    }
  }
  if (current.size()) {
    res.push_back(std::move(current));
  }
  return res;
}

string reverseWords(string s) {
  auto res = splitter(s);
  std::string str_res;
  for (auto iter = res.rbegin(); iter != res.rend(); ++iter) {
    if (iter != res.rbegin()) {
      str_res += std::string(" ");
    }
    str_res += (*iter);
  }
  cout << str_res << endl;
  return str_res;
}

int main() {
  reverseWords("Hello World!");
  return 0;
}