/*
Platform - Basic Problem
Problem Name - GCD of Two Numbers
Link - N/A

Idea:
We use Euclid’s Algorithm.
The GCD of two numbers a and b is the same as GCD of b and (a % b).
We keep reducing the problem until b becomes 0.

Steps:
1. If b == 0, return a.
2. Otherwise, call gcd(b, a % b).
3. Repeat until b becomes 0.
4. The final value of a is the GCD.

Why it works:
At each step, we reduce the problem size using modulo.
This keeps the GCD unchanged but makes numbers smaller,
leading us to the answer efficiently.

TC: O(log n)
Reason: The numbers reduce quickly with each modulo operation.

SC: O(log n)
Reason: Recursive calls use stack space.

Pattern:
Recursion / Math
*/
#include<iostream>
using namespace std;
// int gcd(int a, int b){
//     int mini = min(a, b);
//     for(int i=mini;i>=1;i--){
//         if((a % i == 0) && (b % i == 0)){
//             return i;
//         }
//     }
//     return -1;
// }
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}
int main(){
    int a,b;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;

    cout<<gcd(a, b);
    return 0;

}
