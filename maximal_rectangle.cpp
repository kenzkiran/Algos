// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing only 1's and return its area.

#include <iostream>
#include <vector>
using namespace std;

bool IsOne(char c) { return c == '1'; };

size_t maxarea = 0;

void UpdateArea(size_t r, size_t c, size_t rr, size_t cc) {
  size_t area = (rr - r + 1) * (cc - c + 1);
  maxarea = std::max(area, maxarea);
}

int maximalRectangle(vector<vector<char>> &matrix) {
  size_t rows = matrix.size();
  size_t cols = 0;
  if (rows) {
    cols = matrix[0].size();
  }
  for (size_t r = 0; r < rows; ++r) {
    for (size_t c = 0; c < cols; ++c) {
      size_t max_row = rows - 1;
      for (size_t cc = c; cc <= (cols - 1); ++cc) {
        if (IsOne(matrix[r][cc])) {
          // go check all rows
          for (size_t rr = r; rr <= max_row;) {
            if (IsOne(matrix[rr][cc])) {
              UpdateArea(r, c, rr, cc);
              rr++;
            } else {
              max_row = rr - 1;
              break;
            }
          }
        } else {
          break;
        }
      }
    }
  }
  return maxarea;
}

int main() {
  vector<vector<char>> matrix = {{'1', '1', '1'}, {'0', '0', '0'}};
  cout << "Area " << maximalRectangle(matrix) << endl;
}