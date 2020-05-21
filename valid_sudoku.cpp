// Check if a given sudoku is valid
#include <map>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
  int kNumRows = 0;
  int kNumCols = 0;

  bool CheckValid(const std::vector<char> &in) {
    std::map<char, bool> char_map;
    for (auto i = 0; i < in.size(); ++i) {
      if (in[i] == '.') 
        continue;
      if (char_map.count(in[i])) {
        return false;
      } else {
        char_map[in[i]] = true;
      }
    }
    return true;
  }
  bool IsSubMatrixValid(vector<vector<char>> &board) {
    for (auto r = 0; r < kNumRows; r += 3) {
      for (auto c = 0; c < kNumCols; c += 3) {
        std::vector<char> mat;
        for (auto rr = r; rr < (r + 3); rr++) {
          for (auto cc = c; cc < (c + 3); ++cc) {
            mat.push_back(board[rr][cc]);
            if (!CheckValid(mat)) {
              return false;
            }
          }
        }
      }
    }
  }

  bool IsColumnOk(vector<vector<char>> &board) {
    for (auto i = 0; i < kNumCols; ++i) {
      std::vector<char> col_vec;
      for (auto r = 0; r < kNumRows; ++r) {
        col_vec.push_back(board[r][i]);
        if (!CheckValid(col_vec)) {
          return false;
        }
      }
    }
    return true;
  }
  bool IsRowOk(vector<vector<char>> &board) {
    for (auto r = 0; r < kNumRows; ++r) {
      if (!CheckValid(board[r])) {
        return false;
      }
    }
    return true;
  }
  bool isValidSudoku(vector<vector<char>> &board) {
    kNumRows = board.size();
    if (kNumRows) {
      kNumCols = board[0].size();
    }
    if (kNumCols != 9 || kNumRows != 9) {
      return false;
    }
    return IsRowOk(board) && IsColumnOk(board) && IsSubMatrixValid(board);
  }
};

int main() {
 vector<vector<string>> in{
    { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
    { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
    { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
    { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
    { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
    { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
    { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
    { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
    { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
  };

  Solution s;
  std::cout<<s.isValidSudoku(in);
}