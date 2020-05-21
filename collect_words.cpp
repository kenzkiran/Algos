// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where
// "adjacent" cells are those horizontally or vertically neighboring. The same
// letter cell may not be used more than once.

// Example:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int kNumRows;
  int kNumCols;
  int kMaxRows;
  int kMaxCols;
  std::string theword;
  vector<vector<bool>> state;
  void ResetState() {
    state.clear();
    for (auto i = 0; i < kNumRows; ++i) {
      std::vector<bool> col(kNumCols, false);
      state.push_back(col);
    }
  }
  bool CollectLetters(vector<vector<char>> &board, int r, int c,
                      std::string &current, vector<vector<bool>> &state) {
    if (r < 0 || r > kMaxRows || c < 0 || c > kMaxCols || state[r][c] == true) {
      return false;
    }

    if (board[r][c] != theword[current.size()]) {
      return false;
    }

    current.push_back(theword[current.size()]);
    if (current == theword) {
      return true;
    }

    state[r][c] = true;
    if (CollectLetters(board, r + 1, c, current, state) ||
        CollectLetters(board, r - 1, c, current, state) ||
        CollectLetters(board, r, c + 1, current, state) ||
        CollectLetters(board, r, c - 1, current, state)) {
      return true;
    }
    state[r][c] = false;
    current.pop_back();
    return false;
  }
  bool exist(vector<vector<char>> &board, string word) {
    if (word.empty()) {
      return true;
    }
    theword = word;
    kNumRows = board.size();
    if (kNumRows) {
      kMaxRows = kNumRows - 1;
      kNumCols = board[0].size();
      kMaxCols = kNumCols - 1;
    }
    ResetState();
    for (auto r = 0; r < kNumRows; ++r) {
      for (auto c = 0; c < kNumCols; ++c) {
        ResetState();
        std::string current = "";
        if (board[r][c] == word[0]) {
          if (CollectLetters(board, r, c, current, state)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main() {
  vector<vector<char>> input = {
      {'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
  std::string theword = "AAB";
  Solution s;
  s.exist(input, theword);
  return 0;
}