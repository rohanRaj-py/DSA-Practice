/*
Platform - GeeksforGeeks
Problem Name - Find Missing and Repeating
Link - https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
Date: 01-03-2026

Idea:
Use Cyclic Sort.
Numbers are in range 1 to n.
Place each number at its correct index (num → num-1 index).
After placement, the index where nums[i] != i+1 gives:
- nums[i] → repeating number
- i+1 → missing number

Steps:
1. Traverse array.
2. While current element is not at correct position,
   swap it with its correct index (nums[i] - 1).
3. After sorting, traverse again.
4. If nums[i] != i+1:
   - nums[i] is repeating
   - i+1 is missing

Why it works:
Each number should ideally be at index (value - 1).
Duplicate prevents correct placement of one number.
Mismatch reveals both missing and repeating numbers.

TC: O(n)
SC: O(1)

Pattern:
Cyclic Sort / Index Placement
*/
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& nums) {
        // code here
        int missingNumber = -1;
        int repeatingNumber = -1;
        int i = 0;
        while(i<nums.size()){
            while(nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
            i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i+1){
                return {nums[i], i+1};
            }
        }
        return {missingNumber, repeatingNumber};
    }
};
