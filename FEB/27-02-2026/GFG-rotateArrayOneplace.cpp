/*
GFG - Rotate Array by One (Clockwise)
Date: 27-02-2026

Idea:
1. Store last element.
2. Shift all elements one step to right.
3. Place stored element at index 0.

TC: O(n)
SC: O(1)

Pattern:
Array Shifting
*/

class Solution {
  public:
    void rotate(vector<int> &arr) {

        int n = arr.size();
        int temp = arr[n - 1];

        for(int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = temp;
    }
};
