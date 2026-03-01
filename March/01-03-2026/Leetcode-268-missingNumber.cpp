/*
Platform - LeetCode
Problem Name - Missing Number
Link - https://leetcode.com/problems/missing-number/
Date: 01-03-2026

Idea:
Use XOR property to cancel out equal numbers.
XOR all numbers from 0 to n and all elements of array.
Remaining value will be the missing number.

Steps:
1. Let n = size of array.
2. Initialize ans = 0.
3. XOR numbers from 1 to n.
4. XOR all elements of array.
5. Return ans.

Why it works:
XOR of same numbers becomes 0 (a ^ a = 0).
All present numbers cancel out.
Only missing number remains.

TC: O(n)
SC: O(1)

Pattern:
Bit Manipulation / XOR Trick
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 1; i <= n; i++){
            ans ^= i;
        }

        for(int i = 0; i < n; i++){
            ans ^= nums[i];
        }

        return ans;
    }
};


// other approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size()-1;
        int ans = -1;
        while(i <= j){
            int mid = (i+j)>>1;
            if(nums[mid] != mid){
                ans = mid;
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return ans == -1? nums.size():ans;
        
    }
};
