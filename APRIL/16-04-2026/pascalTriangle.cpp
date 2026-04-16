/*
Platform - Basic Problem
Problem Name - Pascal’s Triangle using nCr
Link - N/A

Idea:
Each element in Pascal’s Triangle is calculated using nCr (combination).
For row i and column j → value = iCj.

Steps:
1. Take input n (number of rows).
2. For each row i from 0 to n-1:
      for each column j from 0 to i:
            print nCr(i, j)
3. Move to next line after each row.

Why it works:
Pascal’s Triangle follows combination formula:
nCr = n! / (r! * (n-r)!)
We compute it efficiently using iterative multiplication.

TC: O(n²)
Reason: Two nested loops.

SC: O(1)
Reason: No extra space used.

Pattern:
Math / Pascal’s Triangle
*/

#include<iostream>
#include<vector>
using namespace std;

int ncr(int n, int r){
    int res = 1;

    for(int i = 0; i < r; i++){
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main(){
    int n;
    cout<<"Enter:";
    cin>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout<<ncr(i, j)<<" ";
        }
        cout<<endl;
    }
}
