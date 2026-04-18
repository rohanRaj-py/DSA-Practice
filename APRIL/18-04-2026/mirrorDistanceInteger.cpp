/*
Platform - Basic Problem
Problem Name - Mirror Distance of a Number
Link - https://leetcode.com/problems/mirror-distance-of-an-integer/description/?envType=daily-question&envId=2026-04-18

Idea:
We reverse the number and find the absolute difference
between the original number and its reverse.

Steps:
1. Reverse the given number.
2. Subtract reversed number from original number.
3. Take absolute value of the result.
4. Return the result.

Why it works:
Reversing the number gives its mirror form.
The difference between original and reversed number
gives the mirror distance.

TC: O(log n)
Reason: We process each digit once.

SC: O(1)
Reason: Only variables are used.

Pattern:
Math / Digit Manipulation
*/

#include<iostream>
#include<vector>
using namespace std;
long long rev(int n){
    long long r = 0;
    while(n != 0){
        r = r * 10 + (n%10);
        n = n/10;
    }
    return r;
}
int mirrorDistance(int n) {
    return abs(n - rev(n));
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<mirrorDistance(n);
    return 0;
}
