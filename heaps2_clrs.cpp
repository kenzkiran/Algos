#include <iostream>
#include <vector>
#include <optional>
#include "common.h"

// This algorithm follows procedure from "Intro to Algorithm by Cormen, Lesierson, Rivest, Stein"
void MaxHeapify(std::vector<int>& arr, size_t k) {
  if (k >= arr.size())
    return;

  int left = (k * 2)  + 1;
  int right = left + 1;
  int largest = 0;
  if (left < arr.size() && arr[left] > arr[k]) {
    largest = left;
  } else {
    largest = k;
  }

  if (right < arr.size() && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != k) {
    // swap k and largest
    auto temp = arr[largest];
    arr[largest] = arr[k];
    arr[k] = temp;
    MaxHeapify(arr, largest);
  }
}

void MinHeapify(std::vector<int>& arr, int k) {
  if (k >= arr.size()) {
    return;
  }
  int left = 2*k + 1;
  int right = left + 1;
  int smallest = -1;

  if (left < arr.size() && arr[left] < arr[k]) {
    smallest = left;
  } else {
    smallest = k;
  }

  if (right < arr.size() && arr[right] < arr[smallest]) {
    smallest = right;
  }

  if (smallest != k) {
    auto temp = arr[smallest];
    arr[smallest] = arr[k];
    arr[k] = temp;
    MinHeapify(arr, smallest);
  }
}

void DoMaxHeapifyArray(std::vector<int>& arr) {
  for (int i = arr.size()/2 - 1; i >=0; --i) {
    MaxHeapify(arr, i);
  }
}
void DoMinHeapifyArray(std::vector<int>& arr) {
  for (int i = arr.size()/2 - 1; i >= 0; --i) {
    MinHeapify(arr, i);
  }
}



std::optional<int> HeapExtractMax(std::vector<int>& arr) {
  if (arr.empty()) {
    return std::nullopt;
  }
  int max = arr[0];
  arr[0] = arr.back();
  arr.pop_back();
  MaxHeapify(arr, 0);
  return max;
}

std::optional<int> HeapExtractMin(std::vector<int>& arr) {
  if (arr.empty()) {
    return std::nullopt;
  }
  int min = arr[0];
  arr[0] = arr.back();
  arr.pop_back();
  MinHeapify(arr, 0);
  return min;
}


void DoHeapSortArray(std::vector<int>& arr, size_t heap_size) {
  // build first max heap
  DoMaxHeapifyArray(arr);
  std::vector<int> sorted_arr;
  
  size_t len = arr.size();
  for (int i = len - 1; i >= 1; --i) {
    // swap first and last element
    sorted_arr.push_back(arr[0]);
    arr[0] = arr[i];
    arr.pop_back();
    MaxHeapify(arr, 0);
  }
  sorted_arr.push_back(arr[0]);
  std::swap(arr, sorted_arr);
}


bool CheckMinHeap(std::vector<int>& arr) {
  auto i = 0;
  auto half_point = arr.size()/2 -1;

  while (i <= half_point) {
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < arr.size() && arr[left] < arr[i]) {
      return false;
    }
    if (right < arr.size() && arr[right] < arr[i]) {
      return false;
    }
    i++;
  }
  return true; 
}


bool CheckMaxHeap(std::vector<int>& arr) {
  auto i = 0;
  auto half_point = arr.size()/2 - 1;
  cout<<"Ravi Half Point value: "<<arr[half_point]<<endl;
  while (i <= half_point) {
    auto left = 2*i + 1;
    auto right = 2*i + 2;
    if (left < arr.size()) {
      if (arr[left] > arr[i]) {
        return false;
      }
    }
    if (right < arr.size()) {
      if (arr[right] > arr[i]) {
        return false;
      }
    }
    i++;
  }
  return true;
}

void MaxHeapInsert(std::vector<int>& arr, int key) {
  arr.push_back(key);
  auto i = arr.size() - 1;
  int parent;
  while(i > 0) {
    parent = (i + 1)/2 - 1;
    if (parent >= 0 && arr[parent] < arr[i]) {
      auto temp = arr[i];
      arr[i] = arr[parent];
      arr[parent] = temp;
      i = parent;
    } else {
      break;
    }
  }
}

int main() {
  std::vector<int> input = {4,1,3,2,16,9,10,14,8,7};
  DoMaxHeapifyArray(input);
  DumpVector(input);
  MaxHeapInsert(input, 18);
  cout <<"Max Heap is : "<<CheckMaxHeap(input)<<endl;
  DumpVector(input);

  // std::vector<int> copy = input;
  // DoMinHeapifyArray(copy);
  // DumpVector(copy);
  // cout <<"Min Heap is : "<<CheckMinHeap(copy)<<endl;
  // DoMaxHeapifyArray(input);

  // if (auto val = HeapExtractMin(copy)) {
  //   cout<<"Min : "<<*val<<endl;
  // }

  // if (auto val = HeapExtractMin(copy)) {
  //   cout<<"Min : "<<*val<<endl;
  // }

  // if (auto val = HeapExtractMax(input)) {
  //   cout<<"Max: "<<*val<<endl;
  // }

  // MaxHeapInsert(input, 16);
  

  // if (auto val = HeapExtractMax(input)) {
  //   cout<<"Max: "<<*val<<endl;
  // }

  // // DoHeapSortArray(input, input.size());
  // cout <<"Max Heap is : "<<CheckMaxHeap(input)<<endl;
  // DumpVector(input);
}