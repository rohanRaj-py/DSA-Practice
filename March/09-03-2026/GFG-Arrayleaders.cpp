/*
Platform - GeeksforGeeks
Problem Name - Leaders in an Array
Link - https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
Date: 09-03-2026

Idea:
A leader is an element that is greater than or equal to
all elements to its right.

The rightmost element is always a leader.

So we traverse the array from right to left
while keeping track of the maximum element seen so far.

Steps:
1. Start from the last element of the array.
2. Initialize maxLeader as the last element.
3. Add the last element to the result array.
4. Traverse the array from right to left.
5. If the current element is greater than or equal to maxLeader:
      add it to the result
      update maxLeader
6. Since we traverse from right to left,
   insert elements at the beginning of the result.
7. Return the result array.

Why it works:
By scanning from right to left, we always know
the maximum element that appears on the right side.

If the current element is greater than or equal to this maximum,
it means no element on its right is larger,
so it is a leader.

TC: O(n)

SC: O(k)  (k = number of leaders)

Pattern:
Reverse Traversal / Maximum Tracking
*/


class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int i = arr.size()-1;
        int maxLeader = arr[i];
        vector<int> ans;
        while(i >= 0){
            if(arr[i] >= maxLeader){
                ans.insert(ans.begin(), arr[i]);
                maxLeader = arr[i];
            }
            i--;
        }
        return ans;
    }
};


class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int i = arr.size()-1;
        int maxLeader = arr[i];
        vector<int> ans;
        while(i >= 0){
            if(arr[i] >= maxLeader){
                // ans.insert(ans.begin(), arr[i]);
                ans.push_back(arr[i]);
                maxLeader = arr[i];
            }
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
