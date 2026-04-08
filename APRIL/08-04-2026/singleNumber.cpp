/*
Platform - Basic Problem (LeetCode - Single Number)
Problem Name - Single Number
Link - https://leetcode.com/problems/single-number/

Idea:
We use XOR operation.
All duplicate numbers cancel each other,
and only the unique number remains.

Steps:
1. Initialize ans = 0.
2. Traverse the array.
3. XOR each element with ans.
4. Return ans.

Why it works:
XOR of a number with itself becomes 0.
So duplicate elements cancel out,
and only the single occurring element is left.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: No extra space is used.

Pattern:
Bit Manipulation / XOR
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans ^= nums[i];
    }
    return ans;
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

    cout<<"single number: "<<singleNumber(arr);
    return 0;
}

