/*
Platform - Basic Problem
Problem Name - Selection Sort
Link - N/A

Idea:
In selection sort, we repeatedly find the smallest element
from the unsorted part of the array and place it at the correct position.

Steps:
1. Start from index i = 0.
2. Assume current index is the minimum.
3. Traverse the remaining array to find the actual minimum element.
4. Swap the found minimum with arr[i].
5. Repeat for all elements.

Why it works:
In every iteration, the smallest element from the unsorted part
is placed at its correct position.
Gradually, the array becomes sorted from left to right.

TC: O(n²)
Reason: Two nested loops are used.

SC: O(1)
Reason: Sorting is done in-place without extra space.

Pattern:
Sorting / Selection Sort
*/
#include<iostream>
#include<vector>
using namespace std;
 void selectionSort(vector<int> &arr) {
     
    for(int i=0;i<arr.size()-1;i++){
        int mini = i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[i],arr[mini]);
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
    selectionSort(v);

    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}
