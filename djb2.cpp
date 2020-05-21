/* Simple string hash using  */
#include <iostream>
#include <string>

using namespace std;
const unsigned long kNumBuckets = 100;
unsigned long djb2hash(const char *str) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  return hash % kNumBuckets;
}

int main() {
  std::string name("riddhi");
  cout<<djb2hash(name.c_str())<<std::endl;
  cout<<djb2hash("Riddhi")<<std::endl;
}