/*
Platform - Basic Problem (LeetCode - Subarray Sum Equals K)
Problem Name - Count Subarrays with Sum K
Link - https://leetcode.com/problems/subarray-sum-equals-k/

Idea:
We use prefix sum and hashmap.
If (sum - k) exists, it means a subarray with sum k is found.
We count how many times that prefix appeared.

Steps:
1. Initialize sum = 0 and maxCnt = 0.
2. Use hashmap to store prefix sum frequency.
3. Traverse the array:
      add current element to sum
4. If sum == k:
      increment count
5. If (sum - k) exists in map:
      add its frequency to count
6. Increase frequency of current sum in map.
7. Return maxCnt.

Why it works:
If sum[j] - sum[i] = k,
then subarray (i+1 to j) has sum k.
Hashmap helps us count all such occurrences efficiently.

TC: O(n)
Reason: We traverse the array once.

SC: O(n)
Reason: Hashmap stores prefix sums.

Pattern:
Prefix Sum + HashMap
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<long long, int> prefixMap;
    int sum = 0;
    int maxCnt = 0;
    for(int i = 0;i<nums.size();i++){
        sum += nums[i];
        if(sum == k){
            maxCnt++;
        }
        if(prefixMap.find(sum - k) != prefixMap.end()){
            maxCnt += prefixMap[sum - k];
        }
        prefixMap[sum]++;
    }
    return maxCnt;
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
    cout<<"Target K:";
    cin>>k;
    cout<<"Total number of subarray equal to target: "<<subarraySum(arr, k);
    return 0;
}
