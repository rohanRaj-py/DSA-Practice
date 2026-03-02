/*
Platform - LeetCode
Problem Name - Maximum Subarray
Link - https://leetcode.com/problems/maximum-subarray/
Date: 02-03-2026

Idea:
Use Kadane’s Algorithm.
If running sum becomes negative,
it cannot contribute to a future maximum,
so reset it to 0.
Keep track of maximum sum seen so far.

Steps:
1. Initialize sum = 0 and maxSum = INT_MIN.
2. Traverse the array.
3. Add current element to sum.
4. Update maxSum = max(maxSum, sum).
5. If sum becomes negative:
      reset sum = 0.
6. After traversal, return maxSum.

Why it works:
A negative prefix reduces total sum.
So we discard it and start fresh.
This guarantees we always consider
the maximum possible subarray.

TC: O(n)
SC: O(1)

Pattern:
Kadane’s Algorithm / Greedy / Dynamic Programming
*/
class Solution {
public:
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
};
