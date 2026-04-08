/*
Platform - Basic Problem (LeetCode - Max Consecutive Ones)
Problem Name - Maximum Consecutive Ones
Link - https://leetcode.com/problems/max-consecutive-ones/

Idea:
We traverse the array and count consecutive 1s.
If we encounter a 0, we reset the count.
We keep track of the maximum count.

Steps:
1. Initialize maxOne = 0 and maxi = 0.
2. Traverse the array.
3. If element is 1:
      increment maxOne
      update maxi
4. If element is 0:
      reset maxOne to 0.
5. Return maxi.

Why it works:
We count consecutive 1s and reset when a 0 appears.
This ensures we always track the longest streak of 1s.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: Only variables are used.

Pattern:
Array Traversal / Counting
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxOne = 0;
    int maxi = 0;
    int j = 0;
    while(j < nums.size()){
        if(nums[j] == 1){
            maxOne += 1;
            maxi = max(maxi, maxOne);
        }
        else{
            maxOne = 0;
        }
        j++;
    }
    return maxi;
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

    cout<<"Maximum consecutive Ones:"<<findMaxConsecutiveOnes(arr);
    return 0;
}
