/*
Platform - Basic Problem (LeetCode - Rearrange Array Elements by Sign)
Problem Name - Rearrange Array by Sign
Link - https://leetcode.com/problems/rearrange-array-elements-by-sign/

Idea:
We place positive numbers at even indices
and negative numbers at odd indices using a new array.

Steps:
1. Create a result array of same size.
2. Initialize two pointers:
      pos = 0 (for positive → even index)
      neg = 0 (for negative → odd index)
3. Traverse the array:
      if element > 0:
            place at index 2 * pos
            increment pos
      else:
            place at index 2 * neg + 1
            increment neg
4. Return result array.

Why it works:
Since equal number of positive and negative elements are given,
we can directly place them at alternate positions.

TC: O(n)
Reason: We traverse the array once.

SC: O(n)
Reason: We use an extra array.

Pattern:
Array / Two Pointer / Index Placement
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    // vector<int> neg;
    // vector<int> pos;

    // for(int i=0;i<nums.size();i++){
    //     if(nums[i] < 0){
    //         neg.push_back(nums[i]);
    //     }
    //     else{
    //         pos.push_back(nums[i]);
    //     }
    // }
    // int i=0;
    // int j=0;
    // int k = 0;
    // while(i < neg.size() && j < pos.size()){
    //     nums[k++] = pos[i++];
    //     nums[k++] = neg[j++];
    // }
    // return nums;
    vector<int> ans(nums.size(), 0);
    int pos = 0;
    int neg = 0;
    int i=0;
    while(i < nums.size()){
        if(nums[i] > 0){
            ans[2*pos] = nums[i];
            pos++;
        }
        else{
            ans[2*neg + 1] = nums[i];
            neg++;
        }
        i++;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;

    vector<int> v;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }

    vector<int> ans = rearrangeArray(v);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}
