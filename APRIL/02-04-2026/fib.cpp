/*
Platform - Basic Problem
Problem Name - Fibonacci Number (DP - Memoization)
Link - N/A

Idea:
Fibonacci can be solved using recursion, but it has repeated calculations.
To optimize it, we store already computed values in a dp array (memoization).

Steps:
1. If n == 0 return 0.
2. If n == 1 return 1.
3. If dp[n] is already calculated, return it.
4. Otherwise:
      dp[n] = fibbo(n-1) + fibbo(n-2)
5. Store the result in dp and return it.

Why it works:
Instead of recalculating the same values again and again,
we store results in dp array.
This avoids repeated work and makes the solution efficient.

TC: O(n)
Reason: Each value from 0 to n is computed only once.

SC: O(n)
Reason: dp array + recursion stack.

Pattern:
Dynamic Programming / Memoization
*/

#include<iostream>
#include<vector>
using namespace std;

int fibbo(int n, vector<int>& dp){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = fibbo(n-1, dp) + fibbo(n-2, dp);
    return dp[n];
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;

    vector<int> dp(n+1, -1);
    cout<<fibbo(n, dp);
    return 0;
}
