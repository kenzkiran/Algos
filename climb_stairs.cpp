/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
std::vector<unsigned int> Steps{1, 2};
const unsigned NumSteps = Steps.size();

void dumpVector(const std::vector<unsigned int>& vec)
{
  auto print = [](const int &n) { std::cout << " " << n; };
  for_each(vec.begin(), vec.end(), print);
  cout<<endl;
}

void waysToClimb(int total_steps, std::vector<unsigned>& current)
{
  if (total_steps == 0) {
    dumpVector(current);
    return;
  }

  for (auto i = 0; i < NumSteps; ++i)
  {
    int new_val = total_steps - Steps[i];
    if (new_val >= 0) {
      auto new_total = total_steps - Steps[i];
      current.push_back(Steps[i]);
      waysToClimb(new_total, current);
      current.pop_back();
    }
  }
}

int main()
{
  std::vector<unsigned int> path;
  waysToClimb(4, path);
}