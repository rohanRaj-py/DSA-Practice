/*
Platform - LeetCode
Problem Name - Best Time to Buy and Sell Stock
Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Date: 09-03-2026

Idea:
We want to buy the stock at the lowest price
and sell it later at the highest possible price.

Instead of checking every pair of days,
we track the minimum price seen so far
and calculate the profit for each day.

Steps:
1. Initialize minStock = INT_MAX.
2. Initialize maxProfit = 0.
3. Traverse the prices array.
4. Update the minimum stock price seen so far.
      minStock = min(minStock, prices[i])
5. Calculate profit if we sell today.
      profit = prices[i] - minStock
6. Update the maximum profit.
7. Return maxProfit.

Why it works:
At every step we maintain the minimum price
before the current day.

This ensures we always buy at the lowest price
and check the profit if we sell on the current day.

TC: O(n)

SC: O(1)

Pattern:
Array Traversal / Greedy / Minimum Tracking
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int maxProfit = INT_MIN;
        // for(int i=0;i<prices.size();i++){
        //     for(int j=i+1;j<prices.size();j++){
        //         maxProfit = max(maxProfit , prices[j] - prices[i]);
        //     }
        // }
        // return maxProfit < 0?0:maxProfit;

        int minStock = INT_MAX;
        int maxProfit = 0;
        for(int i=0;i<prices.size();i++){
            minStock = min(minStock, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minStock);
        }
        return maxProfit;
    }
};
