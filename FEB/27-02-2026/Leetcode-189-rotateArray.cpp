/*
LC 189 - Rotate Array
Date: 27-02-2026

1. Reverse first (n-k) elements
2. Reverse last k elements
3. Reverse entire array

TC: O(n)
SC: O(1)

Pattern:
Array Reversal Technique
*/

class Solution {
public:
    void rotation(vector<int>& nums, int i, int j){
        while(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        rotation(nums, 0, n-k-1);
        rotation(nums, n-k, n-1);
        rotation(nums, 0, n-1);
    }
};
