/*
LC 26 - Remove Duplicates from Sorted Array
Date: 27-02-2026

Approach:
Two pointer technique.
- i tracks position of last unique element.
- j scans the array.
If nums[j] != nums[i], move i forward and place nums[j].

TC: O(n)
SC: O(1)

Pattern:
Two Pointers (Slow & Fast)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int i = 0;
        int j = 1;
        while(j < nums.size()){
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                i++;
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return i+1;
    }
};
