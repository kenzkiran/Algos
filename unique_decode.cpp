// A message containing letters from A-Z is being encoded to numbers using the following mapping:
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26

#include <iostream>
#include <string>
#include <cstdio>


using namespace std;
unsigned paths = 0;

void PossibleDecodePaths(std::string& input) {

  // case 1: Try two digit first
  if (input.length() >= 2) {
    int val = (input[0] - '0') * 10 +  (input[1] - '0');
    if (val >= 1 && val <= 26) {
      if (input.length() == 2) { // implies we are good
        paths++;
      } else {
        auto new_in = input.substr(2);
        PossibleDecodePaths(new_in);
      }
    }
  }

  // case 2: Try 1 digit
  if (input.length() >= 1) {
    int val = input[0] - '0';
    if (val >= 1 && val <= 9) {
      if (input.length() == 1) { // implies we are good
        paths++;
      } else {
        auto new_in = input.substr(1);
        PossibleDecodePaths(new_in);
      }
    }
  }
}

int main() {
  std::string input = "1221";
  PossibleDecodePaths(input);
  cout<<"Ravi Num Paths : "<<paths<<endl;
  return 0;
}