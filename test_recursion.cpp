#include <iostream>
#include <vector>
using namespace std;

int kNumCols = 0;
int kNumRows = 0;
void dojob(std::vector<vector<int>>& input, int r, int c) {
  if (r < 0 || r > (kNumRows - 1) || c < 0 || c > (kNumCols - 1) || input[r][c]) {
    return;
  }
  input[r][c] = 1;
  cout<<"Marked "<<r<<", "<<c<<endl;
  dojob(input, r + 1, c);
  dojob(input, r - 1, c);
  dojob(input, r, c + 1);
  dojob(input, r, c - 1);
  return;
}
int main() {

  std::vector<vector<int>> input = {{0,0,0}, {0,0,0} , {0,0,0}};
  kNumRows = input.size();
  kNumCols = input[0].size();
  dojob(input, 2, 2);

}
