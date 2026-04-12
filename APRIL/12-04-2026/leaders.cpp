/*
Platform - Basic Problem (GFG - Leaders in an Array)
Problem Name - Leaders in an Array
Link - https://www.geeksforgeeks.org/problems/leaders-in-an-array/

Idea:
A leader is an element greater than or equal to all elements to its right.
We traverse from right to left and keep track of maximum element seen so far.

Steps:
1. Initialize maxLeader = INT_MIN.
2. Traverse array from right to left.
3. If current element >= maxLeader:
      add it to result
      update maxLeader
4. Reverse the result (or insert at beginning).
5. Return result.

Why it works:
While traversing from right, we always know the maximum element
to the right side. So we can directly check if current element is a leader.

TC: O(n)
Reason: We traverse the array once.

SC: O(n)
Reason: We store leaders in a new vector.

Pattern:
Array / Traversal
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> leaders(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size()-1;
    int maxLeader = INT_MIN;
    int i=n;
    while(i >= 0){
        if(arr[i] >= maxLeader){
            ans.insert(ans.begin(), arr[i]);
            maxLeader = arr[i];
        }
        i--;
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

    vector<int> l = leaders(v);
    for(auto x:l){
        cout<<x<<" ";
    }
    return 0;
}
