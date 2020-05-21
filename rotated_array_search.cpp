    #include <iostream>
    #include <vector>

    using namespace std;
    
    int searchRange(vector<int>& nums, int start, int end, int target) {
      if (start < 0 || start >= nums.size() || end < 0 || end >= nums.size()) {
        return -1;
      }

      int middle = 0;
      while(end > start) {
        middle = (start + end) / 2;  
        if (nums[middle] == target) {
          return middle;
        }
        if (nums[middle] < target) {
          start = middle + 1;
        } else {
          end = middle - 1;
        }
      }
      if (nums[end] == target) {
        return end;
      }
      return -1;
    }
    
    int search(vector<int>& nums, int target) {
      int pivot = -1;
      int start = 0;
      int end = nums.size() - 1;
      int middle = 0;

      while (end - start > 1) {
        middle = (end + start) / 2;
        cout<<"Ravi start end middle"<<start<<" "<<end<<" "<<middle<<endl;
        if (nums[middle] > nums[start] && nums[middle] < nums[end]) {
          end = middle;
        } else {
          start = middle;
        }
      }
      if (nums[end] < nums[start]) {
        pivot = end;
      } else {
        pivot = start;
      }
      
      if (target == nums[pivot]) {
        return pivot;
      }

      
       auto index = searchRange(nums, pivot + 1, nums.size() - 1, target);
       if (index == -1) {
         return searchRange(nums,0, pivot - 1, target);
       }
       return index;
      }

    int main() {
      std::vector<int> input = {3,5,1};// {4,5,6,7,0,1,2};
      cout<<search(input, 3)<<endl;
    }
