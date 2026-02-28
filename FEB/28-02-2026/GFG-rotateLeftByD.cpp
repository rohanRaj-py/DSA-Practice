/*
GFG - Rotate Array by D Positions (Left Rotation)
Date: 28-02-2026

Idea:
Instead of shifting elements one by one (which is slow),
we use the Reversal Algorithm.

Steps:
1. Reverse first d elements.
2. Reverse remaining n-d elements.
3. Reverse the whole array.

This automatically places the first d elements at the end.

Why d = d % n?
Because if d > n, rotating n times gives the same array.

TC: O(n)
SC: O(1)

Pattern:
Array Rotation using Reversal Technique
*/

class Solution {
  public:
    void rotate(vector<int>& arr, int i, int j){
        while(i < j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        d = d%n;
        
        rotate(arr, 0, d-1);
        rotate(arr, d, n-1);
        rotate(arr, 0, n-1);
    }
};
