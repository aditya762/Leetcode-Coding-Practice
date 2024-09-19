class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // DP table where dp[i][j] indicates whether s[0...i-1] matches p[0...j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Empty pattern matches with empty string
        dp[0][0] = true;

        // Deals with patterns like '*', '**', etc. at the start
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // '*' can match zero characters (dp[i][j-1]) or one/more characters (dp[i-1][j])
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    // Single character match or '?' match
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};
