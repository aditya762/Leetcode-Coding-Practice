class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // dp[i][j] means if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: empty string matches with empty pattern
        dp[0][0] = true;

        // Fill the first row where the string is empty but the pattern is not
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];  // '*' can eliminate the preceding element
            }
        }

        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Case 1: Current characters match or the pattern has '.'
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // Case 2: Pattern contains '*'
                else if (p[j - 1] == '*') {
                    // '*' eliminates the preceding character (0 occurrence case)
                    dp[i][j] = dp[i][j - 2];

                    // '*' matches one or more of the preceding character
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        // The result is stored in dp[m][n], which means whether s[0..m-1] matches p[0..n-1]
        return dp[m][n];
    }
};
