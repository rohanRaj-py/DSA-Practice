/*
Platform - Basic Problem (LeetCode - Check if Array is Sorted and Rotated)
Problem Name - Check if Array is Sorted and Rotated
Link - https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

Idea:
In a sorted and rotated array, there can be at most one place
where the order breaks (nums[i] > nums[i+1]).
If more than one such break exists, the array is not valid.

Steps:
1. Initialize count = 0.
2. Traverse the array from 0 to n-2:
      if nums[i] > nums[i+1], increment count.
3. Also check last and first element:
      if nums[n-1] > nums[0], increment count.
4. If count <= 1 → return true, else false.

Why it works:
A rotated sorted array has only one point
where the increasing order breaks.
If we find more than one such point,
it means the array is not properly rotated.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: No extra space is used.

Pattern:
Array / Traversal
*/

#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int>& nums) {
    int cnt = 0;

    for(int i=0;i<nums.size()-1;i++){
        if(nums[i] > nums[i+1] ){
            cnt++;
        }
    }
    if(nums[0] < nums[nums.size() - 1]){
        cnt++;
    }

    return cnt<=1;
}
int main(){

    vector<int> arr;

    int n;
    cout<<"Enter n:";
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }

    if(check(arr)){
        cout<<"Sorted and Rotated";
    }
    else{
        cout<<"Not";
    }
    return 0;
    
