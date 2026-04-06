/*
Platform - Basic Problem (LeetCode - Remove Duplicates from Sorted Array)
Problem Name - Remove Duplicates from Sorted Array
Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Idea:
Since the array is sorted, duplicate elements are next to each other.
We use two pointers to keep track of unique elements
and move them to the front of the array.

Steps:
1. Initialize i = 0 (points to last unique element).
2. Traverse array using j from 0 to n-1.
3. If nums[j] is not equal to nums[i]:
      increment i
      swap nums[i] and nums[j]
4. Continue till end.
5. Return i + 1 (count of unique elements).

Why it works:
Because the array is sorted, duplicates are adjacent.
We shift only unique elements to the front,
so first part of array contains all unique values.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: No extra space is used (in-place operation).

Pattern:
Two Pointer / Array
*/

#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    int j = 0;

    while(j < nums.size()){
        if(nums[j] != nums[i]){
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }
    return i + 1;
}

int main(){
    vector<int> arr;

    int n;
    cout<<"Enter n:";
    cin>>n;

    int val;
    for(int i = 0; i < n; i++){
        cin>>val;
        arr.push_back(val);
    }

    cout<<"Unique Element:"<<removeDuplicates(arr);
}
