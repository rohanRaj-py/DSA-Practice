/*
Platform - Basic Problem (LeetCode - Rotate Image)
Problem Name - Rotate Matrix by 90 Degrees
Link - https://leetcode.com/problems/rotate-image/

Idea:
To rotate matrix by 90° clockwise:
1. Transpose the matrix
2. Reverse each row

Steps:
1. Traverse upper triangle and swap matrix[i][j] with matrix[j][i].
2. For each row, reverse it.

Why it works:
Transpose converts rows to columns.
Reversing rows gives the correct rotated position.

TC: O(n²)
Reason: We traverse the matrix.

SC: O(1)
Reason: In-place operation.

Pattern:
Matrix / Transpose + Reverse
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    // transpose the matrix
    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    // reverse the each rows
    for(auto& arr:matrix){
        reverse(arr.begin(), arr.end());
    }
}
int main(){
    int n;
    cout<<"Enter cols: ";
    cin>>n;
    vector<vector<int>> arr(n, vector<int> (n));
    int val;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>val;
            arr[i][j] = val;
        }
    }

    rotate(arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;

    }
    return 0;

}
