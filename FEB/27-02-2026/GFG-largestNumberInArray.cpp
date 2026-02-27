/*
Find Largest Element in Array
Platform: GFG

Use STL max_element().
TC: O(n)

Traverse once and track maximum.
TC: O(n)
SC: O(1)

Concept:
Basic array traversal.
*/

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        // int maxi = *max_element(arr.begin(), arr.end());
        // return maxi;
        int maxi = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i] > maxi){
                maxi = arr[i];
            }
        }
        return maxi;
    }
};
