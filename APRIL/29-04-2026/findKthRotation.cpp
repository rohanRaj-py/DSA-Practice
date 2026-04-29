/*
Platform - Basic Problem (GFG - Rotation Count in Rotated Sorted Array)
Problem Name - Find Number of Rotations
Link - N/A

Idea:
The number of rotations is equal to the index of the smallest element.
We use binary search to find the pivot point where rotation happens.

Steps:
1. Initialize s = 0 and e = n - 1.
2. While s <= e:
   - Find mid = (s + e) / 2.
3. If nums[mid] > nums[mid + 1]:
   - Pivot found → return mid + 1.
4. If nums[mid] < nums[0]:
   - Minimum lies on left → move left → e = mid - 1.
5. Else:
   - Minimum lies on right → move right → s = mid + 1.
6. If no pivot found:
   - Array is not rotated → return 0.

Why it works:
In a rotated sorted array, the smallest element is the rotation point.
Binary search helps locate this point efficiently.

TC: O(log n)
SC: O(1)

Pattern:
Binary Search / Rotated Array
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findKRotation(vector<int> &nums) {
    int s = 0;
    int e = nums.size()-1;
    int n = nums.size();
    while(s <= e){
        int mid = (s+e)>>1;
        if(mid+1<n && nums[mid] > nums[mid+1]){
            return mid+1;
        }
        else if(nums[mid] < nums[0]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return 0;
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


    cout<<findKRotation(v);
    return 0;
}
