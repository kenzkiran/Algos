// Given input Number (in base 10), B base index
// Output N base B.
// If input is N = 3 and B = 2: output 11

#include <iostream>
#include <vector>
#include "common.h"

using namespace std;
std::vector<int> MakeBase(int number, int base) {
  std::vector<int> res;
  while (number > base) {
    res.push_back(number % base);
    number = number / base;
  }
  

  std::vector<int> temp;
  temp.push_back(number);
  for (int i = (res.size() - 1); i >=0; --i) {
    temp.push_back(res[i]);
  }

  cout<<"Ravi Result:  "<<number<<" base "<<base<<": ";
  DumpVector(temp);
  return temp;
} 

int main() {
  MakeBase(1024, 16);
}


