/*
LC 179 - Largest Number

Idea:
Convert numbers to string.
Sort using custom comparator (a+b > b+a).
Handle edge case when result starts with '0'.

TC: O(n log n)
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(to_string(nums[i]));
        }
        sort(temp.begin(), temp.end(), [](const string &a, const string &b){
            return a + b > b + a;
        });
        if(temp[0] == "0"){
            return "0";
        }
        string ans = "";
        for(int i=0;i<temp.size();i++){
            ans += temp[i];
        }
        return ans;
    }
};
