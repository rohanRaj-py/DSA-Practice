/*
Platform - Basic Problem
Problem Name - Count Number of Digits in an Integer
Link - N/A

Idea:
When we divide a number by 10, its last digit gets removed.
So by repeatedly dividing the number until it becomes 0,
we can count how many digits it has.

Steps:
1. Take a counter variable cnt = 0.
2. Run a loop while n is not equal to 0.
3. In each iteration:
      increase cnt by 1
      divide n by 10
4. Return cnt.

Why it works:
Each division removes one digit from the number.
So the number of times we divide until it becomes 0
is equal to the number of digits.

TC: O(log n)
Reason: In every step, the number is divided by 10.

SC: O(1)
Reason: No extra space is used, only a few variables.

Pattern:
Math / Digit Manipulation
*/

#include<iostream>
using namespace std;
int countDigits(int n){
    int cnt = 0;
    while(n != 0){
        cnt++;
        n = n/10;
    }
    return cnt;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<countDigits(n);
    return 0;
}
