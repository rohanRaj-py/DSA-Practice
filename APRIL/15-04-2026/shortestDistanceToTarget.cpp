/*
Platform - Basic Problem (LeetCode - Shortest Distance to Target String in a Circular Array)
Problem Name - Closest Target String in Circular Array
Link - https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/

Idea:
We treat the array as circular and check both directions
from the starting index to find the shortest distance.

Steps:
1. Get size n of array.
2. Traverse step from 0 to n-1:
      compute forward index = (startIndex + step) % n
      compute backward index = (startIndex - step + n) % n
3. If either index matches target → return step.
4. If not found → return -1.

Why it works:
In a circular array, shortest distance can be either forward or backward.
By checking both directions at each step,
we guarantee the minimum distance.

TC: O(n)
Reason: In worst case, we check all elements.

SC: O(1)
Reason: No extra space is used.

Pattern:
Circular Array / Simulation
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int closestTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size();
    for(int step = 0; step < n; step++){
        int forward = (startIndex + step) % n;
        int backward = (startIndex - step + n) % n;

        if(words[forward] == target || words[backward] == target) return step;
    }

    return -1;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;

    vector<string> words;
    string word;
    for(int i=0;i<n;i++){
        cin>>word;
        words.push_back(word);
    }
    string target;
    cout<<"Enter target:";
    cin>>target;

    int startIndex;
    cout<<"Enter startIndex:";
    cin>>startIndex;
    cout<<closestTarget(words, target, startIndex);
    return 0;
}
