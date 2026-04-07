/*
Platform - Basic Problem
Problem Name - Rotate Array by One Position (Right)
Link - N/A

Idea:
We store the last element and shift all elements
one position to the right, then place the last element at the front.

Steps:
1. Store last element in temp.
2. Shift elements from right to left:
      arr[i] = arr[i-1]
3. Place temp at index 0.

Why it works:
By shifting all elements to the right,
we create space at the beginning where we place the last element.
This results in rotation by one position.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: Only one extra variable is used.

Pattern:
Array / Rotation
*/
#include<iostream>
#include<vector>
using namespace std;

void rotateByOne(vector<int>& v){
    int temp = v[v.size()-1];
    for(int i=v.size()-1;i > 0;i--){
        v[i] = v[i-1];
    }
    v[0]  = temp;
    return;
}
int main(){
    vector<int> v;
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }

    rotateByOne(v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
