// Rotate a matrix by 90 deg in place
// First Implementation will be for fixed 3 row/col
#include <iostream>

const int kMatrixSize = 3;
void dumpMatrix(const int** matrix) {
  for (size_t i = 0; i < kMatrixSize; ++i) {
    for (size_t j = 0; j < kMatrixSize; ++j) {
      printf("%d  ", matrix[i][j]);
    }
    printf("\n");
  }
}

int* matrix[kMatrixSize];

void Init() {
  for (size_t i = 0; i < kMatrixSize; ++i) {
    matrix[i] = new int[kMatrixSize];
    int* row = matrix[i];
    for (size_t j = 0; j < kMatrixSize; ++j) {
      row[j] = i * kMatrixSize + j + 1;
    }
  }
}


void InPlaceRotation(int** matrix) {
  for(size_t c = 0; c < (kMatrixSize - 1); ++c) {
    int r = 0;
    int new_r = -1;
    int new_c = -1;
    int start_r = r;
    int start_c = c;
    int start_val = matrix[start_r][start_c];
    while(!(r == new_r && c == new_c)) {
      new_r = start_c;
      new_c = (kMatrixSize - 1) - start_r;
      printf("%d , %d --> %d , %d\n", start_r, start_c, new_r, new_c);
      int temp = matrix[new_r][new_c];
      matrix[new_r][new_c] = start_val;
      start_r = new_r;
      start_c = new_c;
      start_val = temp;
    }
  }
}


int main() {
  Init();
  dumpMatrix((const int **)matrix);
  InPlaceRotation((int **)matrix);
  dumpMatrix((const int **)matrix);
}