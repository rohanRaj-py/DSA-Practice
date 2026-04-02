/*
Platform - Basic Problem
Problem Name - Bubble Sort
Link - N/A

Idea:
In bubble sort, we repeatedly compare adjacent elements
and swap them if they are in the wrong order.
After each pass, the largest element moves to its correct position.

Steps:
1. Run a loop from i = 0 to n-2.
2. In each iteration, compare adjacent elements:
      if arr[j] > arr[j+1], swap them.
3. After each pass, the largest element is placed at the end.
4. Repeat until the array is sorted.

Why it works:
In every iteration, the largest element "bubbles up"
to its correct position at the end of the array.
After multiple passes, the entire array becomes sorted.

TC: O(n²)
Reason: Two nested loops are used.

SC: O(1)
Reason: Sorting is done in-place without extra space.

Pattern:
Sorting / Bubble Sort
*/

#include<iostream>
#include<vector>
using namespace std;


void bubbleSort(vector<int>& arr) {
    // code here
    for(int i=0;i<arr.size()-1;i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }
    bubbleSort(v);

    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}
