class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;  // If there's 0 or 1 day, no profit can be made

        // maxProfit[k][i] means the maximum profit using at most k transactions up to day i
        std::vector<std::vector<int>> maxProfit(3, std::vector<int>(n, 0));

        for (int k = 1; k <= 2; ++k) {
            int maxDiff = -prices[0];  // Keep track of the maximum difference
            for (int i = 1; i < n; ++i) {
                // Update maxProfit for k transactions and day i
                maxProfit[k][i] = std::max(maxProfit[k][i - 1], prices[i] + maxDiff);
                // Update maxDiff to be the best profit we can have after a transaction
                maxDiff = std::max(maxDiff, maxProfit[k - 1][i] - prices[i]);
            }
        }

        return maxProfit[2][n - 1];  // Return the max profit with at most 2 transactions
    }
};