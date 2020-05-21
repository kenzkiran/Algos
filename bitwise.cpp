#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    unsigned int x = 0;
    
    x = 0;
    x = ~x;
    x = x >> 1;
    cout<<"Hi: "<<hex<<x<<endl;
    return 0;
}