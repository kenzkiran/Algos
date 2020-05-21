// heaps

#include <iostream>
#include <vector>
#include "common.h"

void MaxHeapify(std::vector<int>& arr) {
  int last = arr.size() - 1;
  int parent = (last - 1) / 2;
  while (last > 0 && parent >= 0 &&  arr[last] > arr[parent] ) {
    auto temp = arr[parent];
    arr[parent] = arr[last];
    arr[last] = temp;
    last = parent;
    parent = (last - 1)/2;
  }
}

int main() {
  std::vector<int> input_arr = {10, 12, 1, 3, 20, 14, 15, 17, 19, 5, 2, 8};
  std::vector<int> heap_arr;
  for (auto i = 0; i < input_arr.size(); ++i) {
    heap_arr.push_back(input_arr[i]);
    MaxHeapify(heap_arr);
  }
  DumpVector(heap_arr);
}

