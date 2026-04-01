/*
Platform - Basic Problem
Problem Name - Armstrong Number
Link - N/A

Idea:
An Armstrong number is a number where the sum of cubes of its digits
is equal to the number itself.
So we extract each digit, cube it, and add it to a sum.

Steps:
1. Store the original number in a variable (num).
2. Initialize ams = 0.
3. Run a loop while n != 0:
      extract digit using n % 10
      add cube of digit to ams
      remove last digit from n
4. Compare ams with original number.
5. If equal → Armstrong number, else not.

Why it works:
We break the number into digits and rebuild a value
using the problem condition (cube of digits).
If the rebuilt value matches the original,
then it satisfies the Armstrong condition.

TC: O(log n)
Reason: We process each digit once.

SC: O(1)
Reason: Only a few variables are used.

Pattern:
Math / Digit Manipulation
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool armstrongNumber(int n) {
    int ams = 0;
    int num = n;

    while(n != 0){
        int digit = n % 10;
        ams += pow(digit, 3);
        n = n / 10;
    }

    if(ams == num){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    if(armstrongNumber(n)){
        cout<<"Armstrong number";
    }
    else{
        cout<<"Not armstrong number";
    }
}
