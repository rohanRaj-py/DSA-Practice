/*
Platform - Basic Problem (LeetCode - Move Zeroes)
Problem Name - Move Zeroes
Link - https://leetcode.com/problems/move-zeroes/

Idea:
We use two pointers.
One pointer (i) keeps track of position to place non-zero elements,
and the other pointer (j) traverses the array.

Steps:
1. Initialize i = 0 and j = 0.
2. Traverse the array using j.
3. If nums[j] is not zero:
      swap nums[i] and nums[j]
      increment i
4. Continue till end.

Why it works:
All non-zero elements are moved to the front,
and zeroes automatically shift to the end.
Order of non-zero elements is maintained.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: No extra space is used (in-place).

Pattern:
Two Pointer / Array
*/

#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0;
    int j = 0;

    while(j < nums.size()){
        if(nums[j] != 0){
            swap(nums[i], nums[j]);
            i++;
            
        }
        j++;
    }
}
int main(){
    vector<int> v;
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }

    moveZeroes(v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
