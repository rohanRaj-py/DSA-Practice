/*
GFG - Second Largest Element
Date: 27-02-2026

-----------------------------------------
Approach 1 (Two Pass):
1. Find first largest element.
2. Traverse again to find largest element 
   not equal to first largest.
TC: O(n) + O(n) = O(n)
SC: O(1)

-----------------------------------------
Approach 2 (Optimal - Single Pass):
Maintain two variables:
- firstMax
- secondMax

Update them in one traversal.
TC: O(n)
SC: O(1)

Edge Case:
If no second largest exists → return -1
*/


// Approach 1
  // code here
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        find first largest
        int firstMaxi = INT_MIN;
        int secondMaxi = INT_MIN;
        for(int i=0;i<arr.size();i++){
          if(firstMaxi < arr[i]){
              firstMaxi = arr[i];
          }
        }
        for(int i=0;i<arr.size();i++){
          if(arr[i] > secondMaxi && arr[i] != firstMaxi){
              secondMaxi = arr[i];
          }
        }
        if(secondMaxi == INT_MIN){
          return -1;
        }
        return secondMaxi;
    }
};

// Approach 2
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int firstMaxi = INT_MIN;
        int secondMaxi = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(firstMaxi < arr[i]){
                secondMaxi = firstMaxi;
                firstMaxi = arr[i];
            }
            
            if(arr[i] > secondMaxi && arr[i] != firstMaxi){
                secondMaxi = arr[i];
            }
        }
        return secondMaxi == INT_MIN?-1:secondMaxi;
    }
    
};
