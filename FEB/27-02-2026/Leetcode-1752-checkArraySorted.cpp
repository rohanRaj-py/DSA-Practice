/*
LC 1752 - Check if Array Is Sorted and Rotated
Date: 27-02-2026

Idea:
Count how many times order breaks 
(i.e., nums[i] > nums[i+1]).

For a sorted rotated array,
there can be at most ONE break point.

Also check last and first element relation.

TC: O(n)
SC: O(1)

Key Concept:
Sorted array + at most one rotation.
*/

class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i+1]) {
                cnt++;
            }
        }

        // circular check
        if(nums[n-1] > nums[0]) {
            cnt++;
        }

        return cnt <= 1;
    }
};
