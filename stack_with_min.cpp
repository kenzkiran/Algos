// Design a stack wiht push, pop and min. All should operation in O(1)

#include<iostream>
#include<map>
#include<vector>

using namespace std;

class MyStack {
  public:
  bool pop(int& val) {
    if (vals.size()) {
      val = vals.back();
      if (val <= min()) {
        mins.pop_back();
      }
      vals.pop_back();
      return true;
    }
    return false;
  }

  void push(int val) {
    if (val <= min()) {
      mins.push_back(val);
    }
    vals.push_back(val);
  }

  int min() {
    if (vals.empty()) {
      return std::numeric_limits<int>::max();
    } else {
      return mins.back();
    }
  }
  size_t size() {
    return vals.size();
  }
  private:
  std::vector<int> mins;
  std::vector<int> vals;
};

int main() {
  MyStack mystack;
  mystack.push(13);
  mystack.push(11);
  mystack.push(10);
  mystack.push(10);
  mystack.push(8);
  int val;
  while(mystack.size()) {
    cout<<"Min :"<<mystack.min()<<endl;
    if (mystack.pop(val)) {
      cout<<"Value: "<<val<<endl;
    }
  }
}

