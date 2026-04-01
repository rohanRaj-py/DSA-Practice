/*
Platform - Basic Problem (LeetCode - Reverse Integer)
Problem Name - Reverse Integer
Link - https://leetcode.com/problems/reverse-integer/

Idea:
We reverse the number by taking digits one by one using modulo (% 10).
While building the reversed number, we must check for overflow
before multiplying and adding the digit.

Steps:
1. Initialize rev = 0.
2. Run a loop while x != 0.
3. Extract last digit using x % 10.
4. Reduce number using x / 10.
5. Before updating rev, check overflow:
      if rev > INT_MAX/10 or (rev == INT_MAX/10 and digit > 7) → return 0
      if rev < INT_MIN/10 or (rev == INT_MIN/10 and digit < -8) → return 0
6. Update rev = rev * 10 + digit.
7. Return rev.

Why it works:
We reverse the number digit by digit.
The overflow check ensures that the reversed number
always stays within integer limits.

TC: O(log n)
Reason: We process each digit once by dividing the number by 10.

SC: O(1)
Reason: No extra space is used, only variables.

Pattern:
Math / Digit Manipulation
*/

#include <iostream>
#include <limits.h>
using namespace std;

int reverse(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int digit = x % 10;
        x = x / 10;

        if ((rev > INT_MAX / 10) || (rev == INT_MAX / 10 && digit > 7))
        {
            return 0;
        }
        if ((rev < INT_MIN / 10) || (rev == INT_MIN / 10 && digit < -8))
        {
            return 0;
        }

        rev = rev * 10 + digit;
    }
    return rev;
}

int main()
{
    int n;
    cout << "Enter: ";
    cin >> n;
    cout << reverse(n);
    return 0;
}
