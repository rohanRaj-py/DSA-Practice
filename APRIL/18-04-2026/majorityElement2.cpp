/*
Platform - Basic Problem (LeetCode - Majority Element II)
Problem Name - Majority Element II
Link - https://leetcode.com/problems/majority-element-ii/

Idea:
At most 2 elements can appear more than n/3 times.
So we track two candidates using Boyer-Moore Voting.

Steps:
1. Initialize two candidates (ele1, ele2) and their counts.
2. Traverse the array:
      if element matches ele1 → cnt1++
      else if matches ele2 → cnt2++
      else if cnt1 == 0 → update ele1
      else if cnt2 == 0 → update ele2
      else decrease both counts
3. Do a second pass to count actual occurrences.
4. If count > n/3, add to answer.

Why it works:
There can be at most 2 elements with frequency > n/3.
Voting process filters potential candidates,
and second pass confirms them.

TC: O(n)
Reason: Two passes over array.

SC: O(1)
Reason: Only a few variables used.

Pattern:
Boyer-Moore Voting Algorithm / Array
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(cnt1 == 0 && nums[i] != ele2){
            cnt1 = 1;
            ele1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i] != ele1){
            cnt2 = 1;
            ele2 = nums[i];
        }
        else if(ele1 == nums[i]) cnt1++;
        else if(ele2 == nums[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ans;
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0;i<nums.size();i++){
        if(ele1  == nums[i]) cnt1++;
        if(ele2 == nums[i]) cnt2++;
    }

    int mini = (nums.size()/3);
    if(cnt1 > mini){
        ans.push_back(ele1);
    }
    if(cnt2 > mini){
        ans.push_back(ele2);
    }
return ans;       
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    int val;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }
    vector<int> ans = majorityElement(v);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}
