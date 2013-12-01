/*
  Insertion sort:
  
  Author:R Ramachandra
  Date: 17th Sept 2013
*/

#include<stdio.h>
#include<iostream>

using namespace std;

void dump(int * a, int len) {
	cout<<"Sorted ListL: [ ";
	for (int i = 0; i < len; ++i)
		cout<<a[i]<<"  ";
	 
	 cout<<"]"<<endl;	 
		
}

/* 

Note: No Error checking:
 * If array is in bounds
 * If array is valid (not null)
*/
void insertion_sort(int * arr, int len)
{

for (int j = 2 ; j < len; ++j) {
	for ( int i = j-1 ; i >= 0 && arr[i+1] < arr[i] ; --i ) {
		/* Swap arr[i] with arr[i+1] */
		int temp = arr[i+1];
		arr[i+1] = arr[i];
		arr[i] = temp;	
	}
}

dump(arr, len);
}



int main()
{
    int array[] = {7,6, 5, 4,3, 2, 1 };
    int len = sizeof(array)/sizeof(int);
    insertion_sort(array, len);
}