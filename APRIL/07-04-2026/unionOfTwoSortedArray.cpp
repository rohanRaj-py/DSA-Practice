/*
Platform - Basic Problem (GFG - Union of Two Sorted Arrays)
Problem Name - Union of Two Sorted Arrays
Link - https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays/

Idea:
We use two pointers to traverse both sorted arrays.
We compare elements and add only unique values to the result.

Steps:
1. Initialize two pointers i = 0 and j = 0.
2. Compare a[i] and b[j]:
      add smaller element to result (avoid duplicates)
      move corresponding pointer
3. If equal, add once and move both pointers.
4. Add remaining elements from both arrays (avoid duplicates).
5. Return result.

Why it works:
Since arrays are sorted, we can merge them like merge sort.
Checking last inserted element avoids duplicates.

TC: O(n + m)
Reason: We traverse both arrays once.

SC: O(n + m)
Reason: We store union in a new vector.

Pattern:
Two Pointer / Merge / Set Logic
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> ans;

    int i = 0, j = 0;

    while(i < a.size() && j < b.size()){
        if(a[i] <= b[j]){
            if(ans.empty() || ans.back() != a[i]){
                ans.push_back(a[i]);
            }
            i++;
        }
        else{
            if(ans.empty() || ans.back() != b[j]){
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    while(i < a.size()){
        if(ans.empty() || ans.back() != a[i]){
            ans.push_back(a[i]);
        }
        i++;
    }

    while(j < b.size()){
        if(ans.empty() || ans.back() != b[j]){
            ans.push_back(b[j]);
        }
        j++;
    }

    return ans;
}

int main(){
    vector<int> a, b;

    int n, m;
    cout<<"Enter size a: ";
    cin>>n;
    cout<<"Enter size b: ";
    cin>>m;

    int val;
    for(int i = 0; i < n; i++){   
        cin>>val;
        a.push_back(val);
    }

    for(int i = 0; i < m; i++){   
        cin>>val;
        b.push_back(val);
    }

    vector<int> temp = findUnion(a, b);

    for(auto x : temp){
        cout<<x<<" ";
    }

    return 0;
}
