/*
Platform - Basic Problem (LeetCode - Majority Element)
Problem Name - Majority Element
Link - https://leetcode.com/problems/majority-element/

Idea:
We use Boyer-Moore Voting Algorithm.
We keep a candidate and a count.
If count becomes 0, we change the candidate.

Steps:
1. Initialize candidate = nums[0] and count = 0.
2. Traverse the array:
      if count == 0:
            set candidate = current element
      if current element == candidate:
            increment count
      else:
            decrement count
3. Return candidate.

Why it works:
Majority element appears more than n/2 times.
So even if we cancel out different elements,
the majority element will remain at the end.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: No extra space is used.

Pattern:
Boyer-Moore Voting Algorithm / Array
*/
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int maxEle = nums[0];
    int cnt = 0;
    for(int i=0;i<nums.size();i++){
        if(maxEle == nums[i]){
            cnt++;
        }
        if(maxEle != nums[i]){
            cnt--;
        }
        if(cnt == 0){
            maxEle = nums[i];
            cnt++;
        }
    }
    return maxEle;
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

    cout<<majorityElement(v);
    return 0;
}
