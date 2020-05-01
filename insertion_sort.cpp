/*
  Insertion sort:

  Author:R Ramachandra
  Date: 17th Sept 2013
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void dump(int *a, int len) {
  cout << "Sorted ListL: [ ";
  for (int i = 0; i < len; ++i)
    cout << a[i] << "  ";

  cout << "]" << endl;
}

/*

Note: No Error checking:
 * If array is in bounds
 * If array is valid (not null)
*/
void insertion_sort(int *arr, int len) {

  for (int j = 2; j < len; ++j) {
    for (int i = j - 1; i >= 0 && arr[i + 1] < arr[i]; --i) {
      /* Swap arr[i] with arr[i+1] */
      int temp = arr[i + 1];
      arr[i + 1] = arr[i];
      arr[i] = temp;
    }
  }

  dump(arr, len);
}

void dumpVector(const std::vector<int> &vec) {
  auto print = [](const int &n) { std::cout << " " << n; };
  for_each(vec.begin(), vec.end(), print);
  cout << endl;
}

void insertion_sort_stl(std::vector<int> &arr) {
  for (auto i = 1; i < arr.size(); ++i) {
    auto key = arr[i];
    for (auto j = i - 1; j >= 0; --j) {
      if (key < arr[j]) {
        auto temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
      // dumpVector(arr);
    }
  }
}

int main() {
  int array[] = {7, 6, 5, 4, 3, 2, 1};
  int len = sizeof(array) / sizeof(int);
  std::vector<int> new_input = {7, 6, 5};
  insertion_sort(array, len);
  insertion_sort_stl(new_input);
  dumpVector(new_input);
}