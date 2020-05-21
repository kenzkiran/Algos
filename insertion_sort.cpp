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
  for (auto i = 1; i < len; ++i) {
    for (auto j = i - 1; j >= 0; --j) {
      if (arr[j + 1] < arr[j]) {
        auto temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
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
  int array[] = { 8, 7, 6, 5, 4, 1, 2};
  int len = sizeof(array) / sizeof(int);
  std::vector<int> new_input = {5, 2, 4, 6, 1, 3};
  insertion_sort(array, len);
  insertion_sort_stl(new_input);
  dumpVector(new_input);
}