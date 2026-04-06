/*
Platform - Basic Problem
Problem Name - Find Greatest Element in Array
Link - N/A

Idea:
We traverse the array and keep track of the maximum element.
If we find a bigger element, we update the maximum.

Steps:
1. Initialize maxi = INT_MIN.
2. Traverse the array.
3. For each element:
      if it is greater than maxi → update maxi.
4. Return maxi.

Why it works:
By checking every element and updating the maximum,
we ensure that at the end, maxi holds the largest value.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: Only one variable is used.

Pattern:
Array Traversal
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findGreater(vector<int>& arr){
    int maxi = INT_MIN;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }

    return maxi;
}

int main(){
    vector<int> arr;

    int n;
    cout<<"Enter n:";
    cin>>n;

    int val;
    for(int i = 0; i < n; i++){
        cin>>val;
        arr.push_back(val);
    }

    cout<<"Greatest Element:"<<findGreater(arr);
}
