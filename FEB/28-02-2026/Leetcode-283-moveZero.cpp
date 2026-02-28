/*
LeetCode - Move Zeroes
Date: 28-02-2026

Idea:
Move all non-zero elements to the front while maintaining order.
Keep a pointer (cnt) to track the position where the next non-zero element should go.

Steps:
1. Traverse the array.
2. If element is non-zero, place it at index 'cnt' and increment cnt.
3. After placing all non-zero elements,
   fill the remaining positions with zero.

This keeps the relative order of elements unchanged.

TC: O(n)
SC: O(1)

Pattern:
Two Pointer / Array Compaction
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        while(cnt != nums.size()){
            nums[cnt] = 0;
            cnt++;
        }
    }
};
