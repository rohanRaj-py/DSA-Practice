/*
Platform - Basic Problem (LeetCode - Rotate Array)
Problem Name - Rotate Array
Link - https://leetcode.com/problems/rotate-array/

Idea:
To rotate the array to the right by k steps,
we use the reversal technique.
First reverse the first part, then the second part,
and finally reverse the whole array.

Steps:
1. Find k = k % n (to handle large k).
2. Reverse first part (0 to n-k-1).
3. Reverse second part (n-k to n-1).
4. Reverse the whole array (0 to n-1).

Why it works:
Reversing parts of the array rearranges elements
in such a way that they achieve the rotated position.
Final reversal gives the correct rotated array.

TC: O(n)
Reason: Each element is visited a constant number of times.

SC: O(1)
Reason: Rotation is done in-place.

Pattern:
Array / Reversal Technique
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void rotateArray(vector<int>& nums, int i, int j){
    while(i <= j){
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    rotateArray(nums, 0, n-k-1);
    rotateArray(nums, n-k, n-1);
    rotateArray(nums, 0, n-1);

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

    int k;
    cout<<"Rotate: ";
    cin>>k;

    rotate(arr, k);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
