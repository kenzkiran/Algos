#include <iostream>
#include <vector>

using namespace std;
int conquer_island(vector<vector<char>>& grid, int r, int c) {
  if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
    return 0;
  }
  grid[r][c] = 0;
  auto area = 1;
  area += conquer_island(grid, r + 1, c);
  area += conquer_island(grid, r - 1, c);
  area += conquer_island(grid, r, c + 1);
  area += conquer_island(grid, r, c - 1);
  return area;
}

int numIslands2(vector<vector<char>>& grid) {
  int res = 0;
  for (auto r = 0; r < grid.size(); ++r) {
    for (auto c = 0; c < grid[0].size(); ++c) {
      if (grid[r][c] == 1) {
        res++;
        conquer_island(grid, r, c);
      }
    }
  }
  return res;
}

int max_area = 0;
int maxAreaOfIsland(vector<vector<int>>& grid) {
  for (auto r = 0; r < grid.size(); ++r) {
    for (auto c = 0; c < grid[0].size(); ++c) {
      auto area = 0;
      if (grid[r][c] == 1) {
       area = conquer_island(grid, r, c);
       max_area = std::max(max_area, area);
      }
    }
  }
  return max_area;
}

int main() {
  vector<vector<char>> grid = { {1,1,0,0,0},
                                {1,1,0,0,0},
                                {0,0,1,0,0},
                                {0,0,0,1,1}
                              };
  cout<<numIslands2(grid)<<endl;
}