class Solution {
public:
    unordered_map<string, bool> dp;  // Memoization table
    
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        
        string key = s1 + " " + s2;  // Unique key for the memoization
        if (dp.find(key) != dp.end()) return dp[key];
        
        int n = s1.size();
        vector<int> count(26, 0);  // To store frequency of characters

        // Check if both strings have the same character frequency
        for (int i = 0; i < n; ++i) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) return dp[key] = false;
        }

        // Recursively check all possible splits
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return dp[key] = true;
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
                return dp[key] = true;
        }

        return dp[key] = false;
    }
};
