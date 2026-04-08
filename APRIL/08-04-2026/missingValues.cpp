/*
Platform - Basic Problem (LeetCode - Missing Number)
Problem Name - Missing Number
Link - https://leetcode.com/problems/missing-number/

Idea:
We use XOR operation.
If we XOR all array elements and all numbers from 1 to n,
the duplicate numbers cancel out and we get the missing number.

Steps:
1. Initialize ans = 0.
2. XOR all elements of the array.
3. XOR all numbers from 1 to n+1.
4. The result will be the missing number.

Why it works:
XOR of a number with itself becomes 0.
So all present numbers cancel out,
and only the missing number remains.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: No extra space is used.

Pattern:
Bit Manipulation / XOR
*/
#include<iostream>
#include<vector>
using namespace std;

int missingNum(vector<int>& arr) {

    int n = arr.size();
    int ans = 0;
    for(int i=0;i<arr.size();i++){
        ans ^= arr[i];
    }
    for(int i=1;i<=arr.size()+1;i++){
        ans ^= i;
    }
    return ans;
}
int main(){
    int n;
    vector<int> v;
    cout<<"Enter n:";
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }

    int missingVal = missingNum(v);
    cout<<missingVal;
    return 0;

    
}
