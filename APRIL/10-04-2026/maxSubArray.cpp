/*
Platform - Basic Problem (LeetCode - Maximum Subarray)
Problem Name - Maximum Subarray
Link - https://leetcode.com/problems/maximum-subarray/

Idea:
We keep adding elements to a running sum.
If the sum becomes negative, we reset it to 0.
We track the maximum sum seen so far.

Steps:
1. Initialize sum = 0 and maxSum = INT_MIN.
2. Traverse the array.
3. Add current element to sum.
4. Update maxSum with maximum of maxSum and sum.
5. If sum becomes negative, reset it to 0.
6. Return maxSum.

Why it works:
A negative sum will reduce future subarray sums,
so we discard it and start fresh.
This ensures we always consider the best subarray.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: Only variables are used.

Pattern:
Kadane’s Algorithm / Array
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    // int maxSum = INT_MIN;
    // for(int i=0;i<nums.size();i++){
    //     int sum = 0;
    //     for(int j=i;j<nums.size();j++){
    //         sum += nums[j];
    //         maxSum = max(maxSum, sum);
    //     }
    // }
    // return maxSum;
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;

    vector<int> v;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }

    cout<<maxSubArray(v);
    return 0;
}
