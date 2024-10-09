class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = INT_MAX;  // Initialize the minimum price to maximum integer value
        int maxProfit = 0;        // Initialize the maximum profit to 0

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;  // Update the minimum price
            } else {
                maxProfit = std::max(maxProfit, price - minPrice);  // Calculate the profit
            }
        }

        return maxProfit;  // Return the maximum profit
    }
};