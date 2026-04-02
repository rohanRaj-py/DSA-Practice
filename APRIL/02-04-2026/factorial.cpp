/*
Platform - Basic Problem
Problem Name - Factorial of a Number
Link - N/A

Idea:
Factorial of a number n is n * (n-1) * (n-2) ... till 1.
We can solve this using recursion by breaking the problem
into smaller subproblems.

Steps:
1. If n == 0 or n == 1, return 1 (base case).
2. Otherwise, return n * factorial(n-1).
3. The function keeps calling itself until it reaches the base case.

Why it works:
Each recursive call reduces the problem size.
Finally, it reaches the base case and then
returns values back by multiplying.

TC: O(n)
Reason: The function is called n times.

SC: O(n)
Reason: Recursive calls use stack space.

Pattern:
Recursion
*/

#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}

int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;

    cout<<factorial(n);
    return 0;
}
