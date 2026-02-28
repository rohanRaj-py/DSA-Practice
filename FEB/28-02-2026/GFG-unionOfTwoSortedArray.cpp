/*
GFG - Union of Two Sorted Arrays
Date: 28-02-2026

Idea:
Since both arrays are sorted, we use two pointers.

1. Compare elements of both arrays.
2. Push the smaller element into result (if not already added).
3. Move that pointer forward.
4. After one array finishes, add remaining elements of the other array.
5. Always check for duplicates before pushing.

TC: O(n + m)
SC: O(n + m)

Pattern:
Two Pointer / Merge Technique
*/
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        vector<int> temp;
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] <= b[j]){
                if(temp.empty() || temp.back() != a[i]){
                    temp.push_back(a[i]);
                    
                }
                i++;
            }
            else{
                if(temp.empty() || temp.back() != b[j]){
                    temp.push_back(b[j]);
                }
                j++;
            }
        }
        
        while(i < a.size()){
            if(temp.empty() || temp.back() != a[i]){
                    temp.push_back(a[i]);
                    
            }
            i++;
        }
        while(j < b.size()){
            if(temp.empty() || temp.back() != b[j]){
                    temp.push_back(b[j]);
                   
            }
             j++;
        }
        return temp;
    }
};
