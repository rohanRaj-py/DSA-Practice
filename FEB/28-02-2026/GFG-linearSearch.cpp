/*
GFG - Linear Search
Date: 28-02-2026

Idea:
Traverse the array from left to right.
If the current element equals x, return its index.
If no element matches after full traversal, return -1.

TC: O(n)
SC: O(1)

Pattern:
Linear Search / Basic Traversal
*/

class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // code here
        for(int i=0;i<arr.size();i++){
            if(arr[i] == x){
                return i;
            }
        }
        return -1;
    }
};
