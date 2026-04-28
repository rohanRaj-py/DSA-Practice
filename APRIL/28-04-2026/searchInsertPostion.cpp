/*
Platform - Basic Problem (LeetCode - Search Insert Position)
Problem Name - Search Insert Position
Link - https://leetcode.com/problems/search-insert-position/

Idea:
We use binary search.
If the element is found → return index.
If not found → return the position where it should be inserted.

Steps:
1. Initialize s = 0 and e = n-1.
2. While s <= e:
      find mid
3. If nums[mid] == target → return mid
4. If nums[mid] < target → search right (s = mid + 1)
5. Else → search left (e = mid - 1)
6. If not found → return s (insertion position)

Why it works:
When loop ends, s points to the correct position
where target should be inserted to maintain sorted order.

TC: O(log n)
Reason: Binary search halves the search space.

SC: O(1)
Reason: No extra space is used.

Pattern:
Binary Search
*/
#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
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
    return s;
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
    cout<<searchInsert(v, target);
    return 0;
}
