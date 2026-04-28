/*
Platform - Basic Problem (LeetCode - Find First and Last Position of Element)
Problem Name - First and Last Occurrence of Element
Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Idea:
We use binary search twice:
1. To find first occurrence (leftmost)
2. To find last occurrence (rightmost)

Steps:
1. For first occurrence:
      if nums[mid] == target:
            store index and move left
2. For last occurrence:
      if nums[mid] == target:
            store index and move right
3. Return both indices.

Why it works:
Binary search helps us efficiently locate
both boundaries of the target element.

TC: O(log n)
Reason: Two binary searches.

SC: O(1)
Reason: No extra space used.

Pattern:
Binary Search / Boundary Finding
*/
#include<iostream>
#include<vector>
using namespace std;
int firstPos(vector<int> &nums, int target){
    int s = 0;
    int e = nums.size()-1;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)>>1;
        if(nums[mid] == target){
            ans = mid;
            e = mid-1;
        }
        else if(nums[mid] > target){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}
    int lastPos(vector<int> &nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s <= e){
            int mid = (s+e)>>1;
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
}
int main(){
    int n;
    cout<<"Enter:";
    cin>>n;
    vector<int> v;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }
    int target;
    cout<<"Enter target:";
    cin>>target;
    int firstOcc = -1;
    int lastOcc = -1;
    firstOcc = firstPos(v, target);
    lastOcc = lastPos(v, target);
    vector<int> ans = {firstOcc, lastOcc};
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}
