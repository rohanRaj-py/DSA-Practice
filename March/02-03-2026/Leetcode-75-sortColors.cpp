/*
Platform - LeetCode
Problem Name - Sort Colors
Link - https://leetcode.com/problems/sort-colors/
Date: 02-03-2026

Idea:
Use Dutch National Flag Algorithm.
Since array contains only 0, 1, and 2,
we can sort in one pass using three pointers.
Maintain:
- 0s on left
- 2s on right
- 1s in middle

Steps:
1. Initialize three pointers:
   - i = 0 (current index)
   - j = 0 (position for next 0)
   - k = n-1 (position for next 2)
2. While i <= k:
   - If nums[i] == 2:
       swap nums[i] with nums[k], decrement k.
   - Else if nums[i] == 0:
       swap nums[i] with nums[j],
       increment both i and j.
   - Else (nums[i] == 1):
       just increment i.
3. Continue until i crosses k.

Why it works:
We divide array into three regions:
- [0 ... j-1] → 0s
- [j ... i-1] → 1s
- [k+1 ... n-1] → 2s
By adjusting pointers correctly,
we ensure elements are placed in correct partition
in a single traversal.

TC: O(n)
SC: O(1)

Pattern:
Dutch National Flag / Three Pointer / Partitioning
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j = 0;
        int k = nums.size()-1;
        while(i<=k){
            if(nums[i] == 2){
                swap(nums[i], nums[k]);
                k--;
            }
            else if(nums[i] == 0){
                swap(nums[i], nums[j]);
                j++;
                i++;
            }
            else{
                i++;
            }
        }
    }
};
