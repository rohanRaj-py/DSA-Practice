#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool search(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int s = 0;
    int e = nums.size()-1;
    while(s <= e){
        int mid = (s+e)>>1;
        if(nums[mid] == target){
            return true;
        }
        else if(nums[mid] < target){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter: ";
    cin>>n;
    vector<int> v;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }
    int target;
    cout<<"Enter target: ";
    cin>>target;

    if(search(v, target)){
        cout<<"Element Exist";
    }
    else{
        cout<<"Element do not exixt";
    }
    return 0;
}
