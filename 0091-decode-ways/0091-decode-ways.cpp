class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: empty string has one way to decode
        dp[1] = s[0] != '0' ? 1 : 0; // Single digit decode
        
        for (int i = 2; i <= n; ++i) {
            int oneDigit = stoi(s.substr(i - 1, 1));
            int twoDigits = stoi(s.substr(i - 2, 2));
            
            if (oneDigit >= 1) {
                dp[i] += dp[i - 1];
            }
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
