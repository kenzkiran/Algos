//
//  merge_sort.cpp
//  
//
//  Created by Ravi on 9/24/13.
//
//
//

#include<iostream>
#include<vector>
#include<limits>

using namespace std;

typedef vector<int> VInt;
typedef VInt::iterator VIter;
const int INFINITY = std::numeric_limits<int>::max();

//int in[] = {7,1,4,2, 2, 12, 3, 15};
int in[] = {7,1, 4, 2, 2, 12, 3, 15};
VInt gInputArray(in, in + sizeof(in)/sizeof(in[0])  );

void dumpVector(const vector<int>&  v)
{
    cout<<"Dumping Vector:"<<endl;
    for(int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<"  ";
    }
    
    
}

void combine(VInt& l, VInt& r, VInt& output)
{
    int i = 0;
    int j = 0;
    while( i < l.size() && j < r.size()) {
        
        if(l[i] < r[j]) {
            output.push_back(l[i++]);
        } else {
            output.push_back(r[j++]);
        }
    }
    
    VIter o_end = output.end();
    
    if( i < l.size()) {
        output.insert(o_end, l.begin()+ i, l.end());
    } else {
        output.insert(o_end, r.begin() + j, r.end());
    }
    
}

void merge_sort(VInt& arr, int p, VInt& sarr)
{
    int len = arr.size();
    int leftLen = p ;
    int rightLen = len - p;
    
    VInt leftSorted;
    VInt rightSorted;
    //cout<<"ll "<<leftLen<<"rl "<<rightLen<<endl;
    if(leftLen > 1) {
        VInt larr(arr.begin(), arr.begin() + p);
        merge_sort(larr,leftLen/2, leftSorted);
    } else{
        //cout<<"only one left"<<endl;
        leftSorted.push_back(arr[0]);
    }
    
    if(rightLen > 1) {
        VInt rarr(arr.begin() + p, arr.end());
        merge_sort(rarr,rightLen/2, rightSorted);
    } else {
        //cout<<"only one right"<<endl;
        rightSorted.push_back(arr[1]);
    }
    
    
    combine(leftSorted, rightSorted, sarr);
    
}

int main()
{
    dumpVector(gInputArray);
    
    VInt sorted;
    merge_sort(gInputArray, gInputArray.size()/2, sorted);
    dumpVector(sorted);
    
}


