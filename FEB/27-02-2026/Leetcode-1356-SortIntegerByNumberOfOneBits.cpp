/*
LC 1356 - Sort Integers by Number of 1 Bits

Brute Force:
- For each number, manually count bits.
- Store (bitCount, number) in vector.
- Sort vector.
TC: O(n log n)

------------------------------------------
Better:
- Use separate countBits() function.
- Use custom comparator in sort.
TC: O(n log n)

TC: O(n log n * k)  // k = number of bits (<= 32)
SC: O(1)
*/

// Bruteforce approach
class Solution {
public:
    int countBits(int n){
        int cnt = 0;
        while(n != 0){
            int last = n&1;
            if(last){
                cnt++;
            }
            n = n>>1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        map<int, vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            int n = countBits(arr[i]);
            mp[n].push_back(arr[i]);
        }
        for(auto &it : mp) {
            sort(it.second.begin(), it.second.end());
            ans.insert(ans.end(), it.second.begin(), it.second.end());
        }
        return ans;
    }
};

// Better approach
class Solution {
public:
    int countBits(int n){
        int cnt = 0;
        while(n != 0){
            cnt += (n & 1);
            n = n >> 1;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end(), [this](const int& a, const int& b){
            int bitsA = countBits(a);
            int bitsB = countBits(b);

            if(bitsA == bitsB)
                return a < b;      

            return bitsA < bitsB;   
        });

        return arr;
    }
};
