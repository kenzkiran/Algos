#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kNumRows = 0;
    int kNumCols = 0;
    std::vector<vector<bool>> state;
    void Conquer(vector<vector<char>>&board, int r, int c) {
      if (r < 0 || r >= kNumRows || c  < 0 || c >= kNumCols ) {
        return;
      }

      if (state[r][c]) {
        return;
      }
      if (board[r][c] == 'X') {
        return;
      }
      state[r][c] = true;


      Conquer(board, r+1, c);
      Conquer(board, r-1, c);
      Conquer(board, r, c + 1);
      Conquer(board, r, c - 1);
    }
    void solve(vector<vector<char>>& board) {
        kNumRows = board.size();
        if (kNumRows) {
          kNumCols = board[0].size();
        }
        for (auto i = 0; i < kNumRows; ++i) {
          std::vector<bool> cols(kNumCols, false);
          state.push_back(cols);
        }

        for (auto r = 0; r < (kNumRows); ++r) {
            for (auto c = 0; c < (kNumCols); ++c) {
                if (r == 0 || c == 0 || r == (kNumRows-1) || c == (kNumCols - 1)) {
                  if (board[r][c] == 'O' && state[r][c] == false) {
                    Conquer(board, r, c);
                  }
                }
            }
        }

        for (auto r = 0; r < (kNumRows); ++r) {
            for (auto c = 0; c < (kNumCols); ++c) {
                if (board[r][c] == 'O' && state[r][c] == false) {
                  board[r][c] = 'X';
                }
            }
        }
    }
};


int main() {

  // std::vector<vector<char>> input = {{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'}};
  std::vector<vector<char>> input = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
  Solution s;
  s.solve(input);
  for (auto r = 0; r < s.kNumRows; r++) {
    for (auto c = 0; c < s.kNumCols; c++) {
      cout<<"  "<<input[r][c]; 
    }
    cout<<endl;
  }
  cout<<"Done "<<endl;
}