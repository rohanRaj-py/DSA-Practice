/*
Platform - Basic Problem (LeetCode - Palindrome Number)
Problem Name - Palindrome Number
Link - https://leetcode.com/problems/palindrome-number/

Idea:
A number is a palindrome if it reads the same forward and backward.
So we reverse the number and compare it with the original number.

Steps:
1. Store the original number in a variable (num).
2. If the number is negative, return false.
3. Initialize rev = 0.
4. Run a loop while x != 0:
      take last digit using x % 10
      add it to rev (rev = rev * 10 + digit)
      remove last digit from x
5. Compare rev with original number.
6. If equal → palindrome, else not.

Why it works:
Reversing the number gives us the number in opposite order.
If both original and reversed numbers are same,
then the number is a palindrome.

TC: O(log n)
Reason: We process each digit once.

SC: O(1)
Reason: Only a few variables are used.

Pattern:
Math / Digit Manipulation
*/

#include<iostream>
using namespace std;

bool isPalindrome(int x) {
    int num = x;
    long long rev = 0;

    if(x < 0){
        return false;
    }

    while(x != 0){
        rev = rev * 10 + (x % 10);
        x = x / 10;
    }

    return rev == num ? true : false;
}

int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;

    if(isPalindrome(n)){
        cout<<"Palindrome number";
    }
    else{
        cout<<"Not palindrome number";
    }

    return 0;
}
