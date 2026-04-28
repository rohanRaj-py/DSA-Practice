/*
Platform - Basic Problem (GFG - Floor and Ceil in Sorted Array)
Problem Name - Find Floor and Ceil
Link - N/A

Idea:
Floor = greatest element ≤ x  
Ceil  = smallest element ≥ x  

We use binary search and update floor & ceil during traversal.

Steps:
1. Initialize s = 0, e = n-1.
2. Initialize floor = -1, ceil = -1.
3. While s <= e:
      find mid
4. If nums[mid] == x:
      return {x, x}
5. If nums[mid] < x:
      update floor = nums[mid]
      move right (s = mid + 1)
6. Else:
      update ceil = nums[mid]
      move left (e = mid - 1)
7. Return {floor, ceil}

Why it works:
Binary search narrows down range.
We keep updating best candidates for floor and ceil.

TC: O(log n)
Reason: Binary search halves search space.

SC: O(1)
Reason: No extra space used.

Pattern:
Binary Search / Floor & Ceil
*/

#include<iostream>
#include<vector>
using namespace std;
vector<int> getFloorAndCeil(vector<int> nums, int x) {

    int s = 0;
    int e = nums.size() - 1;

    int floor = -1;
    int ceil = -1;

    while (s <= e) {
        int mid = (s + e) >> 1;

        if (nums[mid] == x) {
            return {nums[mid], nums[mid]};
        }
        else if (nums[mid] < x) {
            floor = nums[mid];   
            s = mid + 1;
        }
        else {
            ceil = nums[mid];
            e = mid - 1;
        }
    }

    return {floor, ceil};
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
    vector<int> ans = getFloorAndCeil(v, target);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}
