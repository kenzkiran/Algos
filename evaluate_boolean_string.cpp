// Given a string consisting of only 0, 1, A, B, C where
// A = AND
// B = OR
// C = XOR
// Calculate the value of the string assuming no order of precedence and evaluation is done from left to right.

#include <iostream>
#include <string>

using namespace std;

int eval(int lhs, char op, int rhs) {
  if (op == 'A') {
    return lhs & rhs;
  }
  if (op == 'B') {
    return lhs | rhs;
  }
  if (op == 'C') {
    return lhs ^ rhs;
  }
  return lhs;
}

int EvaluateString(const std::string& in) {
  int result = 0;
  bool expect_operator = false;
  char last_operator = 'B';

  // go over entire string
  for (auto i = 0 ; i < in.length(); ++i) {
    char c = in[i];
    // handle case for input values
    if (c == '0' || c == '1') {
      // ensure we are not expecting operator
      if (expect_operator) {
        cout<<"Invalid entry, expecting operator, but received value"<<endl;
        return 0;
      }
      result = eval(result, last_operator, c - '0');
      expect_operator = true;
    } else if (c == 'A' || c == 'B' || c == 'C') {
      // handle case for operator
      if (!expect_operator) {
        cout<<"Invalid entry, not expecting operator, but received operator"<<endl;
        return 0;
      }
      last_operator = c;
      expect_operator = false;
    }
  }

  if (!expect_operator) {
    cout<<"Abrupt ending , expecting value, but did not receive";
  }
  return result;
}

int main() {
  cout<<EvaluateString("1C0")<<endl;
}