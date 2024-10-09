class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxProfit = 0;  // Initialize maximum profit to 0

        for (size_t i = 1; i < prices.size(); ++i) {
            // If the current price is higher than the previous price,
            // we can make a profit by buying at the previous price and selling at the current price
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];  // Add the profit to total maxProfit
            }
        }

        return maxProfit;  // Return the total maximum profit
    }
};