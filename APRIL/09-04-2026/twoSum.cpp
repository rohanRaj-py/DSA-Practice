/*
Platform - Basic Problem (LeetCode - Two Sum)
Problem Name - Two Sum
Link - https://leetcode.com/problems/two-sum/

Idea:
We use a hashmap to store elements and their indices.
For each element, we check if (target - element) already exists.

Steps:
1. Create a hashmap to store value → index.
2. Traverse the array.
3. For each element:
      check if (target - element) exists in map
      if yes → return indices
4. Otherwise, store current element and index in map.
5. If no pair found, return {-1, -1}.

Why it works:
If nums[i] + nums[j] = target,
then nums[j] = target - nums[i].
Hashmap helps us find this quickly in O(1).

TC: O(n)
Reason: We traverse the array once.

SC: O(n)
Reason: Hashmap stores elements.

Pattern:
Hashing / Two Sum
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for(int i=0;i<nums.size();i++){
        int ele = nums[i];
        if(mp.find(target - ele) != mp.end()){
            return {i, mp[target - ele]};
        }
        mp[ele] = i;
    }
    return {-1, -1};
}
int main(){
    int n;
    vector<int> v;
    cout<<"Enter size: ";
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }
    int target;
    cout<<"Target: ";
    cin>>target;
    vector<int> ans = twoSum(v, target);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
    
}
