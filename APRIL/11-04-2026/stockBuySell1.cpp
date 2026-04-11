/*
Platform - Basic Problem (LeetCode - Best Time to Buy and Sell Stock)
Problem Name - Best Time to Buy and Sell Stock
Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Idea:
We track the minimum price (buy price) so far
and calculate profit at each step.
We update maximum profit whenever we find a better deal.

Steps:
1. Initialize stockBuy = prices[0] and maxProfit = 0.
2. Traverse the array from index 1.
3. Update stockBuy = min(stockBuy, current price).
4. Calculate profit = current price - stockBuy.
5. Update maxProfit if profit is greater.
6. Return maxProfit.

Why it works:
We always try to buy at the lowest price seen so far
and sell at the current price to maximize profit.

TC: O(n)
Reason: We traverse the array once.

SC: O(1)
Reason: Only variables are used.

Pattern:
Greedy / Array
*/


#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    // int maxProfit = 0;
    // for(int i=0;i<prices.size();i++){
    //     int diff = 0;
    //     for(int j=i+1;j<prices.size();j++){
    //         diff = prices[j] - prices[i];
    //         maxProfit = max(maxProfit, diff);
    //     }
    // }
    // return maxProfit;
    int maxProfit = 0;
    int stockBuy = prices[0];
    for(int i=1;i<prices.size();i++){
        stockBuy = min(stockBuy, prices[i]);
        maxProfit = max(maxProfit, prices[i] - stockBuy); 
    }
    return maxProfit;

}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;

    vector<int> prices;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        prices.push_back(val);
    }

    cout<<maxProfit(prices);
    return 0;
}
