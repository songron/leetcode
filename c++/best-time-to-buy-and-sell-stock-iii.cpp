class Solution {
public:
    int maxProfit(vector<int> &prices) {
        /* https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
        Two linear scans:
            1. left-to-right: record the maximum profit until the current position through single transaction;
            2. right-to-left: figure out the maximum profit in the left-part and the right-part,
            see if it bring the maximum two-transaction-profits.
        */
        
        const int n = prices.size();
        if (n == 0) return 0;
        
        vector<int> maxProfits(n, 0);
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            maxProfits[i] = maxProfits[i-1];
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else if (prices[i] - minPrice > maxProfits[i]) {
                maxProfits[i] = prices[i] - minPrice;
            }
        }
        
        int maxPrice = prices[n-1], profit = maxProfits[n-1];
        for (int i = n - 2; i > 0; i--) {
            if (prices[i] >= maxPrice) {
                maxPrice = prices[i];
            }
            else {
                int p = maxPrice - prices[i] + maxProfits[i-1];
                if (p > profit) profit = p;
            }
        }
        
        return profit;
    }
};