/*
Platform - Basic Problem (LeetCode - Search in Rotated Sorted Array)
Problem Name - Search in Rotated Sorted Array
Link - https://leetcode.com/problems/search-in-rotated-sorted-array/

Idea:
Find pivot (largest element).
Then apply binary search in correct half.

Steps:
1. Find pivot index.
2. If target lies between nums[0] and nums[pivot]:
      search left side
3. Else:
      search right side

Why it works:
Array is divided into two sorted halves.
Binary search works on sorted part.

TC: O(log n)
SC: O(1)

Pattern:
Binary Search / Rotated Array
*/
#include<iostream>
#include<vector>
using namespace std;
int pivot(vector<int>& nums){
    int s = 0;
    int e = nums.size()-1;
    int n = nums.size();
    while(s <= e){
        int mid = (s+e)>>1;
        if(s == e){
            return s;
        }
        if(mid+1 < n && nums[mid] > nums[mid+1]){
            return mid;
        }
        else if(nums[0] > nums[mid]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return n-1;
}
int bs(vector<int>& nums, int s,int e,int target){
    while(s<=e){
        int mid = (s+e)>>1;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}
int searchRotated(vector<int>& nums, int target){
    int pivotIdx = pivot(nums);
    if(nums[0] >= target && nums[pivotIdx] <= target){
        return bs(nums, 0, pivotIdx, target);
    }
    else{
        return bs(nums, pivotIdx+1, nums.size()-1, target);
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    vector<int> v;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }
    int target;
    cout<<"Enter target: ";
    cin>>target;

    cout<<searchRotated(v, target);
    return 0;
}
