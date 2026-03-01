/*
Platform - LeetCode
Problem Name - Max Consecutive Ones
Link - https://leetcode.com/problems/max-consecutive-ones/
Date: 01-03-2026

Idea:
Traverse the array and count consecutive 1s.
Whenever 0 appears, update maximum and reset count.

Steps:
1. Initialize cnt = 0 and maxOne = 0.
2. Traverse the array.
3. If element is 1, increment cnt.
4. If element is 0, update maxOne and reset cnt.
5. Return maximum of maxOne and cnt.

Why it works:
We continuously count streaks of 1s.
When a 0 breaks the streak, we store the maximum found so far.

TC: O(n)
SC: O(1)

Pattern:
Array Traversal / Counting
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxOne = 0;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == 0 ){
                maxOne = max(maxOne, cnt);
                cnt = 0;
            }
            else{
                cnt++;
            }
            i++;
        }
        return max(maxOne, cnt);
    }
};
