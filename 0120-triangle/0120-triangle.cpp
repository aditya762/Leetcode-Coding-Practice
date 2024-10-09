class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        // Use the last row as the initial dp array
        std::vector<int> dp(triangle.back());

        // Iterate from the second to last row to the top
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                // Update the dp array with the minimum path sum
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }
        }

        // The top element contains the minimum path sum
        return dp[0];
    }
};