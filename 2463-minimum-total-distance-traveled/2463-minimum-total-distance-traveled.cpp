class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();
        
        // DP table: dp[i][j] represents the minimum distance to repair first j robots with the first i factories
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LLONG_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= m; ++i) {
            int pos = factory[i - 1][0], limit = factory[i - 1][1];
            for (int j = 0; j <= n; ++j) {
                // Option 1: Don't use this factory at all
                dp[i][j] = dp[i - 1][j];
                
                // Option 2: Use this factory for up to `limit` robots
                long long dist_sum = 0;
                for (int k = 1; k <= limit && j - k >= 0; ++k) {
                    dist_sum += abs(robot[j - k] - pos);
                    if (dp[i - 1][j - k] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + dist_sum);
                    }
                }
            }
        }

        return dp[m][n];
    }
};
