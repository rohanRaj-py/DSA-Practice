/*
Platform - Basic Problem (GFG / LeetCode Variant)
Problem Name - Longest Subarray with Sum K
Link - N/A

Idea:
We use prefix sum and a hashmap.
If (current sum - k) exists in the map,
it means a subarray with sum k is found.

Steps:
1. Initialize sum = 0 and maxLen = 0.
2. Create a hashmap to store prefix sum and index.
3. Traverse the array:
      add current element to sum
4. If sum == k:
      update maxLen = i + 1
5. If (sum - k) exists in map:
      update maxLen = i - previous index
6. Store sum in map if not already present.
7. Return maxLen.

Why it works:
If sum[j] - sum[i] = k,
then subarray (i+1 to j) has sum k.
Hashmap helps us find previous sums quickly.

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

int longestSubarray(vector<int>& arr, int k){
    unordered_map<long long, int> prefixMap;
    int sum = 0;
    int maxLen = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        if(prefixMap.find(sum - k) != prefixMap.end()){
            maxLen = max(maxLen, i - prefixMap[sum - k]);
        }
        if(prefixMap.find(sum) == prefixMap.end()){
            prefixMap[sum] = i;
        }
    }
    return maxLen;
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
    cout<<"Length of Longest subarray: "<<longestSubarray(arr, k);
    return 0;
}
