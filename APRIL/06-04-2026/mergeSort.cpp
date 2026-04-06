/*
Platform - Basic Problem
Problem Name - Merge Sort
Link - N/A

Idea:
Merge Sort uses divide and conquer.
We divide the array into two halves,
sort both halves, and then merge them.

Steps:
1. Divide the array into two halves using mid.
2. Recursively sort left half.
3. Recursively sort right half.
4. Merge both sorted halves into one sorted array.

Why it works:
Each half is sorted individually,
and merging two sorted arrays gives a fully sorted array.
This process continues until the whole array is sorted.

TC: O(n log n)
Reason: We divide the array log n times and merge takes O(n).

SC: O(n)
Reason: Extra space is used for temporary array during merging.

Pattern:
Divide and Conquer / Sorting
*/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int l, int mid, int r){
    vector<int> temp;
    int i = l;
    int j = mid + 1;

    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= r){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i = 0; i < temp.size(); i++){
        arr[l + i] = temp[i];
    }
}

void mergeSort(vector<int>& arr, int l, int r){
    if(l < r){
        int mid = (l + r) >> 1;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    vector<int> arr;

    int n;
    cout<<"Enter n: ";
    cin>>n;

    int val;
    for(int i = 0; i < n; i++){
        cin>>val;
        arr.push_back(val);
    }

    int l = 0;
    int r = arr.size() - 1; 
    mergeSort(arr, l, r);

    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}
