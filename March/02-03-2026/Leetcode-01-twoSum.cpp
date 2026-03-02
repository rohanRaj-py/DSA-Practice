/*
Platform - LeetCode
Problem Name - Two Sum
Link - https://leetcode.com/problems/two-sum/
Date: 02-03-2026

Idea:
Use Hashing (unordered_map).
For each element, calculate complement = target - nums[i].
If complement already exists in map,
we found the required pair.
Otherwise, store current element with its index.

Steps:
1. Create an unordered_map to store (value → index).
2. Traverse the array.
3. For each element:
   - Compute complement = target - nums[i].
   - If complement exists in map:
       return its stored index and current index.
   - Else store nums[i] in map.
4. If no pair found, return {-1, -1}.

Why it works:
We store previously seen elements.
For each number, we check if the required pair
has already appeared.
This avoids brute force comparison
and reduces time complexity to linear.

TC: O(n)
SC: O(n)

Pattern:
Hashing / Complement Search
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];

            if(mp.find(comp) != mp.end()){
                return {mp[comp], i};
            }

            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};
