/*
Platform - Basic Problem
Problem Name - Second Largest Element in Array
Link - N/A

Idea:
We keep track of two values:
firstMaxi (largest) and secondMaxi (second largest).
While traversing the array, we update them accordingly.

Steps:
1. Initialize firstMaxi and secondMaxi as INT_MIN.
2. Traverse the array.
3. For each element:
      if element > firstMaxi:
            secondMaxi = firstMaxi
            firstMaxi = element
      else if element > secondMaxi AND element != firstMaxi:
            update secondMaxi
4. If secondMaxi is still INT_MIN, return -1.
5. Otherwise return secondMaxi.

Why it works:
We always maintain the largest and second largest values.
Whenever we find a bigger element, we shift values accordingly.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: Only two variables are used.

Pattern:
Array Traversal / Tracking Maximum
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int secondLargest(vector<int>& arr){
    int firstMaxi = INT_MIN;
    int secondMaxi = INT_MIN;

    for(int i=0;i<arr.size();i++){
        if(arr[i] > firstMaxi){
            secondMaxi = firstMaxi;
            firstMaxi = arr[i];
        }

        if(arr[i] > secondMaxi && arr[i] != firstMaxi){
            secondMaxi = arr[i];
        }
    }
    return secondMaxi == INT_MIN?-1:secondMaxi;
}
int main(){
    vector<int> arr;

    int n;
    cout<<"Enter n:";
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }

    cout<<"Greatest Element:"<<secondLargest(arr);
}
