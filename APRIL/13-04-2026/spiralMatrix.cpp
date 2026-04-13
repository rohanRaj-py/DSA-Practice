/*
Platform - Basic Problem (LeetCode - Spiral Matrix)
Problem Name - Spiral Order Traversal of Matrix
Link - https://leetcode.com/problems/spiral-matrix/

Idea:
We use four boundaries (top, bottom, left, right)
and traverse the matrix layer by layer in spiral order.

Steps:
1. Initialize:
      sr = 0, er = m-1 (rows)
      sc = 0, ec = n-1 (columns)
2. Traverse in 4 directions:
      left → right (top row)
      top → bottom (right column)
      right → left (bottom row)
      bottom → top (left column)
3. After each traversal, update boundaries.
4. Repeat until all elements are covered.

Why it works:
We shrink the boundaries after each layer,
ensuring that we traverse every element exactly once
in spiral order.

TC: O(m × n)
Reason: Every element is visited once.

SC: O(1) (excluding output)
Reason: No extra space is used apart from result array.

Pattern:
Matrix / Simulation
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix){
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();
    int sc = 0;
    int ec = n-1;
    int sr = 0;
    int er = m-1;
    int total = m*n;
    int cnt = 0;
    while(cnt < total){
        for(int i=sc;i<=ec && cnt < total;i++){
            ans.push_back(matrix[sr][i]);
            cnt++;
        }
        sr++;
        for(int i=sr;i<=er && cnt < total;i++){
            ans.push_back(matrix[i][ec]);
            cnt++;
        }
        ec--;
        for(int i=ec;i>=sc && cnt < total;i--){
            ans.push_back(matrix[er][i]);
            cnt++;
        }
        er--;
        for(int i=er;i>=sr && cnt < total;i--){
            ans.push_back(matrix[i][sc]);
            cnt++;
        }
        sc++;
    }
    return ans;
}
int main(){
    int m;
    int n;
    cout<<"Enter rows: ";
    cin>>m;
    cout<<"Enter cols: ";
    cin>>n;
    vector<vector<int>> arr(m, vector<int> (n));
    int val;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>val;
            arr[i][j] = val;
        }
    }

    vector<int> ans = spiralOrder(arr);
    for(auto x:ans){
        cout<<x<<' ';
    }
    return 0;

}
