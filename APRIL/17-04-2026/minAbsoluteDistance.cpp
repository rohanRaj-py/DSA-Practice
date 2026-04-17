/*
Platform - Basic Problem
Problem Name - Minimum Mirror Pair Distance
Link - N/A

Idea:
For each number, we check if its reverse has already appeared.
If yes, we calculate the distance between indices.
We keep track of the minimum such distance.

Steps:
1. Create a hashmap to store reversed number → index.
2. Initialize minDist = INT_MAX.
3. Traverse the array:
      if current number exists in map:
            update minDist = min(minDist, i - stored index)
      store reverse of current number in map with index i
4. Return minDist.

Why it works:
If a number and its reverse appear in the array,
they form a mirror pair.
Hashmap helps us quickly check if reverse was seen before.

TC: O(n * d)
Reason: We traverse array once and reverse takes O(d) digits.

SC: O(n)
Reason: Hashmap stores elements.

Pattern:
HashMap / Number Manipulation
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;
int rev(int nums){
    int r = 0;
    while(nums != 0){
        r = r * 10 + (nums%10);
        nums = nums/10;
    }
    return r;
}
int minMirrorPairDistance(vector<int>& v){
    unordered_map<int, int> mp;
    int minDist = INT_MAX;
    for(int i=0;i<v.size();i++){
        if(mp.find(v[i]) != mp.end()){
            minDist = min(minDist, i - mp[v[i]]);
        }
        mp[rev(v[i])] = i;
    }
    return minDist;
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
    cout<<minMirrorPairDistance(v);
    return 0;
}
