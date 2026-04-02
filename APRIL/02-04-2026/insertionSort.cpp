/*
Platform - Basic Problem
Problem Name - Insertion Sort
Link - N/A

Idea:
In insertion sort, we take one element at a time
and place it at the correct position in the sorted part of the array.

Steps:
1. Start from index i = 1.
2. Take the current element and compare it with previous elements.
3. Swap it backwards until it reaches the correct position.
4. Repeat for all elements.

Why it works:
At every step, the left part of the array is already sorted.
We insert the current element into its correct position,
so the sorted portion keeps growing.

TC: O(n²)
Reason: In worst case, each element is compared with all previous elements.

SC: O(1)
Reason: Sorting is done in-place.

Pattern:
Sorting / Insertion Sort
*/

#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    
    for(int i=1;i<arr.size();i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
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
    insertionSort(v);

    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}
