/*
Platform - LeetCode - Find Minimum in Rotated Sorted Array
Problem Name - Find Minimum in Rotated Sorted Array
Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Idea:
The minimum element is the pivot point in a rotated sorted array.
We use binary search to locate the point where the order breaks.

Steps:
1. Initialize s = 0 and e = n - 1.
2. While s <= e:
   - Find mid = (s + e) / 2.
3. If nums[mid] > nums[mid + 1]:
   - Minimum is nums[mid + 1] → return it.
4. If nums[mid] < nums[0]:
   - Minimum lies on left side → move left → e = mid - 1.
5. Else:
   - Minimum lies on right side → move right → s = mid + 1.
6. If no pivot found:
   - Array is not rotated → return nums[0].

Why it works:
In rotated array, only one place exists where order breaks.
That break point gives the smallest element.

TC: O(log n)
SC: O(1)

Pattern:
Binary Search / Rotated Array
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int n = nums.size();

        while(s <= e){
            int mid = (s + e) >> 1;

            if(mid + 1 < n && nums[mid] > nums[mid + 1]){
                return nums[mid + 1];
            }
            else if(nums[mid] < nums[0]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return nums[0];
    }
};
