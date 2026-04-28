/*
Platform - Basic Problem (Lower Bound)
Problem Name - Lower Bound (First element >= target)
Link - N/A

Idea:
We find the first index where element is greater than
or equal to the target.

Steps:
1. Initialize s = 0, e = n-1, ans = n.
2. While s <= e:
      find mid
3. If arr[mid] >= target:
      store mid as answer
      move left (e = mid - 1)
4. Else:
      move right (s = mid + 1)
5. Return ans.

Why it works:
We always try to find the leftmost index
where condition (>= target) is satisfied.

TC: O(log n)
Reason: Binary search halves search space.

SC: O(1)
Reason: No extra space used.

Pattern:
Binary Search / Lower Bound
*/
#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    int s = 0;
    int e = arr.size() - 1;
    int ans = arr.size();   

    while(s <= e){
        int mid = s + (e - s) / 2;

        if(arr[mid] >= target){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter:";
    cin>>n;

    vector<int> v;
    int val;

    for(int i = 0; i < n; i++){
        cin>>val;
        v.push_back(val);
    }

    int target;
    cout<<"Enter target:";
    cin>>target;

    cout<<lowerBound(v, target);

    return 0;
}
