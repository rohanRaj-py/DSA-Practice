/*
Platform - Basic Problem (LeetCode - Binary Search)
Problem Name - Binary Search
Link - https://leetcode.com/problems/binary-search/

Idea:
We repeatedly divide the search space into half.
Compare the middle element with target and decide which half to search.

Steps:
1. Initialize start = 0 and end = n-1.
2. While start <= end:
      find mid = (start + end) / 2
3. If nums[mid] == target → return mid
4. If nums[mid] < target → search right half
5. Else → search left half
6. If not found → return -1

Why it works:
Since array is sorted,
we can eliminate half of the elements in each step.

TC: O(log n)
Reason: Search space reduces by half each time.

SC: O(1)
Reason: No extra space is used.

Pattern:
Binary Search
*/
#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size()-1;
    while(s <= e){
        int mid = (s+e)>>1;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
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
    cout<<search(v, target);
    return 0;
}
