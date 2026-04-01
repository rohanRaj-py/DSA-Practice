/*
Platform - Basic Problem
Problem Name - Print All Divisors of a Number
Link - N/A

Idea:
Instead of checking all numbers from 1 to n,
we only check till sqrt(n).
If i divides n, then n/i is also a divisor.
So we can find divisors in pairs.

Steps:
1. Create a vector to store divisors.
2. Loop from i = 1 to sqrt(n).
3. If i divides n:
      add i to the list
      if i != n/i, also add n/i
4. Sort the list of divisors.
5. Print all elements.

Why it works:
Divisors always come in pairs (i and n/i).
By iterating till sqrt(n), we avoid unnecessary checks
and still find all divisors efficiently.

TC: O(√n log n)
Reason: Loop runs till √n and sorting takes log n time.

SC: O(n)
Reason: We store all divisors in a vector.

Pattern:
Math / Factors / Square Root Optimization
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void print_divisors(int n) {
    vector<int> ans;
    int i = 1;

    while(i <= sqrt(n)){
        if(n % i == 0){
            ans.push_back(i);

            if(i != n / i){
                ans.push_back(n / i);
            }
        }
        i++;
    }

    sort(ans.begin(), ans.end());

    for(auto x : ans){
        cout << x << " ";
    }
}

int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;

    print_divisors(n);
    return 0;
}
