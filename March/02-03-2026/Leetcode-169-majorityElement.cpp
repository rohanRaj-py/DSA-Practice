/*
Platform - LeetCode
Problem Name - Majority Element
Link - https://leetcode.com/problems/majority-element/
Date: 02-03-2026

Idea:
Use Moore’s Voting Algorithm.
If an element appears more than n/2 times,
it will survive all cancellations.
We maintain a candidate element and a counter.
When counter becomes zero, we change candidate.

Steps:
1. Initialize ele = nums[0] and cnt = 1.
2. Traverse array from index 1.
3. If current element equals ele:
      increment count.
   Else:
      decrement count.
4. If count becomes 0:
      update ele to current element
      and reset count to 1.
5. After traversal, ele will be the majority element.

Why it works:
Majority element appears more than n/2 times.
All other elements combined cannot fully cancel it.
Thus it remains as the final candidate.

TC: O(n)
SC: O(1)

Pattern:
Moore’s Voting Algorithm / Cancellation Technique
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n = nums.size();
        // for(int i=0;i<nums.size();i++){
        //     int cnt = 0;
        //     for(int j=i;j<nums.size();j++){
        //         if(nums[i] == nums[j]){
        //             cnt++;
        //             if(cnt > (n/2)){
        //                 return nums[i];
        //             }
        //         }
        //     }
        // }
        // return -1;
       
       int ele = nums[0];
       int cnt = 1;
       for(int i=1;i<nums.size();i++){
            if(ele == nums[i]){
                cnt++;
            }
            else{
                cnt--;
                if(cnt == 0){
                    ele = nums[i];
                    cnt=1;
                }
            }
       }
       return ele;
    }
};
