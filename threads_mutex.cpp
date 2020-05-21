#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int main() {
  std::mutex m;
  {
    std::unique_lock<std::mutex> lock(m);
     {
       lock.unlock();
       std::unique_lock<std::mutex> lock2(m);
     }
  }
  cout<<"end "<<endl;
}