class Solution {
public:
    int maxProfit(vector<int> &prices) {
        /* https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
        Do a linear scan: record the minimum price until now, 
        and see if selling at the current point will bring the maximum profit.
        */
        
        int minPrice = INT_MAX, profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else if (prices[i] - minPrice > profit) {
                profit = prices[i] - minPrice;
            }
        }
        
        return profit;
    }
};