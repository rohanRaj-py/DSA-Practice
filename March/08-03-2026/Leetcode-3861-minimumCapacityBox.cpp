/*
Platform: LeetCode
Problem: Minimum Index of a Valid Capacity
Date: 08-03-2026

Approach:
Linear Scan (Greedy Selection)

Idea:
We are given an array `capacity` where each element represents the
capacity of a container. We also have an `itemSize`.

Our goal is to find the index of the container that:
1. Can hold the item (capacity[i] >= itemSize)
2. Has the smallest capacity among all valid containers.

To achieve this, we traverse the array and keep track of:
- The smallest valid capacity found so far
- Its corresponding index.

Steps:
1. Initialize `ans` with INT_MAX and `idx` with -1.
2. Traverse the capacity array.
3. For each element:
   - Check if capacity[i] >= itemSize.
   - If yes and capacity[i] < ans:
       update ans = capacity[i]
       update idx = i
4. After traversal, return idx.

Edge Case:
If no container can hold the item, idx remains -1.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern:
Array Traversal / Greedy Selection
*/
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = INT_MAX;
        int idx=-1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i] >= itemSize){
               if(capacity[i] < ans){
                   ans = capacity[i];
                   idx = i;
               }
                
            }
        }
        return idx;
    }
};
