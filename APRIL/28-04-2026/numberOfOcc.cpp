/*
Platform - Basic Problem (GFG - Count Occurrences in Sorted Array)
Problem Name - Count Frequency of Element
Link - N/A

Idea:
We find first and last occurrence using binary search.
Frequency = last index - first index + 1.

Steps:
1. Find first occurrence of target.
2. Find last occurrence of target.
3. If not found → return 0.
4. Otherwise → return (last - first + 1).

Why it works:
In sorted array, all occurrences are consecutive.
So difference of indices gives frequency.

TC: O(log n)
Reason: Two binary searches.

SC: O(1)
Reason: No extra space used.

Pattern:
Binary Search / Counting
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
int countFreq(vector<int>& arr, int target) {
    
    int lastOcc = lastPos(arr, target) ;
    int firstOcc = firstPos(arr, target);
    if(lastOcc == -1 && firstOcc == -1){
        return 0;
    }
    return (lastOcc -  firstOcc + 1);
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
    cout<<countFreq(v, target);
    return 0;
}
