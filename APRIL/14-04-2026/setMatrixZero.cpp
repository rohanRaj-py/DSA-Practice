/*
Platform - Basic Problem (LeetCode - Set Matrix Zeroes)
Problem Name - Set Matrix Zeroes
Link - https://leetcode.com/problems/set-matrix-zeroes/

Idea:
If any cell is 0, its entire row and column should become 0.
We use two arrays to mark which rows and columns need to be zero.

Steps:
1. Create two arrays row[] and col[] initialized to 0.
2. Traverse the matrix:
      if matrix[i][j] == 0:
            mark row[i] = 1
            mark col[j] = 1
3. Traverse again:
      if row[i] == 1 OR col[j] == 1:
            set matrix[i][j] = 0

Why it works:
We first store positions of zeroes without modifying matrix.
Then we update matrix based on stored information.

TC: O(m × n)
Reason: We traverse matrix twice.

SC: O(m + n)
Reason: Extra arrays for rows and columns.

Pattern:
Matrix / Marking Rows & Columns
*/

#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    vector<int> row(r, 0);
    vector<int> col(c, 0);

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(row[i] == 1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }
}

int main(){
    int m, n;

    cout<<"Enter rows: ";
    cin>>m;

    cout<<"Enter cols: ";
    cin>>n;

    vector<vector<int>> arr(m, vector<int>(n));

    int val;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>val;
            arr[i][j] = val;
        }
    }

    setZeroes(arr);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
