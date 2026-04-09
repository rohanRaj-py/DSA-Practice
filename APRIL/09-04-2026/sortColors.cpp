
/*
Platform - Basic Problem (LeetCode - Sort Colors)
Problem Name - Sort Colors
Link - https://leetcode.com/problems/sort-colors/

Idea:
We use three pointers to divide the array into three parts:
0s, 1s, and 2s.
This is called the Dutch National Flag Algorithm.

Steps:
1. Initialize:
      i = -1 (end of 0s)
      j = 0  (current element)
      k = n-1 (start of 2s)
2. Traverse while j <= k:
      if nums[j] == 0:
            increment i
            swap nums[i] and nums[j]
            increment j
      else if nums[j] == 2:
            swap nums[j] and nums[k]
            decrement k
      else:
            increment j

Why it works:
We maintain three regions:
0 → i : all 0s
i+1 → j-1 : all 1s
k+1 → n-1 : all 2s
By adjusting pointers, we place elements in correct regions.

TC: O(n)
Reason: Each element is processed once.

SC: O(1)
Reason: Sorting is done in-place.

Pattern:
Two Pointer / Dutch National Flag
*/



#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void sortColors(vector<int>& nums) {
    // int oneCnt = 0;
    // int zeroCnt = 0;
    // int twoCnt = 0;
    // for(int i=0;i<nums.size();i++){
    //     if(nums[i] == 0){
    //         zeroCnt++;
    //     }
    //     else if(nums[i] == 1){
    //         oneCnt++;
    //     }
    //     else{
    //         twoCnt++;
    //     }
    // }
    // int k = 0;
    // for(int i=1;i<=zeroCnt;i++){
    //     nums[k] = 0;
    //     k++;
    // }
    // for(int i=1;i<=oneCnt;i++){
    //     nums[k] = 1;
    //     k++;
    // }
    // for(int i=1;i<=twoCnt;i++){
    //     nums[k] = 2;
    //     k++;
    // }
    int i=-1;
    int j=0;
    int k=nums.size()-1;
    while(j <= k){
        if(nums[j] == 0){
            i++;
            swap(nums[i], nums[j]);
            j++;
        }
        else if(nums[j] == 2){
            swap(nums[k], nums[j]);
            k--;
        }
        else{
            j++;
        }
    }
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

   sortColors(arr);
   for(auto x:arr){
        cout<<x<<" ";
   }
   return 0;
}
