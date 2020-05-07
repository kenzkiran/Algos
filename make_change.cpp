// MakeChange
// Given an infinite number of quaters (25), 10 cents, 5 Cents and pennies.
// Write all possible combination changes

#include <iostream>
#include <vector>

const std::vector<unsigned> kCoins{25, 10, 5, 1};
const size_t kNumCoins = kCoins.size();

using namespace std;
void dumpVector(const std::vector<unsigned int>& vec)
{
  auto print = [](const int &n) { std::cout << " " << n; };
  for_each(vec.begin(), vec.end(), print);
  cout<<endl;
}

void MakeChange(int total, std::vector<unsigned int>& current_change) {
  for(auto i = 0; i < kNumCoins; ++i) {
    int new_total = total - kCoins[i];
    if (new_total == 0) {
      // We found a valid combination; recursion breaker
      current_change.push_back(kCoins[i]);
      dumpVector(current_change);
      current_change.pop_back();
      continue;
    } else if (new_total > 0) {
      current_change.push_back(kCoins[i]);
      MakeChange(new_total, current_change);
      current_change.pop_back();
    } else {
      continue;
    }
  }
}


int main() {
  std::vector<unsigned int> change;
  MakeChange(10, change);
}