/*
Platform - Basic Problem (LeetCode - Valid Palindrome)
Problem Name - Valid Palindrome (String)
Link - https://leetcode.com/problems/valid-palindrome/

Idea:
We use two pointers from start and end.
We ignore non-alphanumeric characters and compare characters
in lowercase to check if the string is a palindrome.

Steps:
1. Initialize two pointers i = 0 and j = s.size() - 1.
2. While i <= j:
      if s[i] is not alphanumeric → move i forward
      if s[j] is not alphanumeric → move j backward
3. If both are valid characters:
      compare them in lowercase
      if not equal → return false
      else move both pointers
4. If loop completes → return true.

Why it works:
By skipping special characters and ignoring case,
we compare only meaningful characters.
Two pointer approach ensures efficient comparison from both ends.

TC: O(n)
Reason: Each character is processed at most once.

SC: O(1)
Reason: No extra space is used.

Pattern:
Two Pointer / String
*/
#include<iostream>
#include<cctype>
using namespace std;

bool isPalindrome(string s) {
    int i = 0;
    int j = s.size()-1;
    while(i <= j){
        if(!isalnum(s[i])){
            i++;
        }
        if(!isalnum(s[j])){
            j--;
        }
        if(isalnum(s[i]) && isalnum(s[j])){
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
    }
    return true;
}
int main(){
    string s;
    getline(cin, s);

    if(isPalindrome(s)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}
