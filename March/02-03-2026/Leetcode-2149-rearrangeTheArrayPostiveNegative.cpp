/*
Platform - LeetCode
Problem Name - Rearrange Array Elements by Sign
Link - https://leetcode.com/problems/rearrange-array-elements-by-sign/
Date: 02-03-2026

Idea:
Since the number of positive and negative elements is equal,
we can place positives at even indices
and negatives at odd indices.
Use a new array and maintain separate pointers
for positive and negative placement.

Steps:
1. Create a result array of same size.
2. Initialize two counters:
      pos = 0 (for even indices)
      neg = 0 (for odd indices)
3. Traverse the original array.
4. If element is positive:
      place it at index (2 * pos) in result
      and increment pos.
   Else:
      place it at index (2 * neg + 1)
      and increment neg.
5. Return the result array.

Why it works:
Since positives and negatives are equal in number,
we can safely alternate them.
Even indices store positives,
odd indices store negatives,
ensuring correct arrangement.

TC: O(n)
SC: O(n)

Pattern:
Array Placement / Index Mapping
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // vector<int> pos;
        // vector<int> neg;

        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] < 0){
        //         neg.push_back(nums[i]);
        //     }
        //     else{
        //         pos.push_back(nums[i]);
        //     }
        // }
        // int i=0;
        // int j = 0;
        // while(i < pos.size()){
        //     nums[j] = pos[i];
        //     j++;
        //     nums[j] = neg[i];
        //     i++;
        //     j++;
        // }
        // return nums;
        int n = nums.size();
        vector<int> ans(n, 0);
        int pos = 0;
        int neg = 0;
        int i = 0;
        while(i < n){
            if(nums[i] > 0 ){
                ans[2*pos] = nums[i];
                pos++;
            }
            else{
                ans[2*neg + 1] = nums[i];
                neg++;
            }
            i++;
        }
        return ans;
    }
};
