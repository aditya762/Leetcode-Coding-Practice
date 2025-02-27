class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> indexMap; // Map each number to its index
        vector<vector<int>> dp(n, vector<int>(n, 2)); // Initialize DP table

        int maxLen = 0;

        // Fill indexMap for quick lookup
        for (int i = 0; i < n; ++i) {
            indexMap[arr[i]] = i;
        }

        // Iterate through all pairs (arr[i], arr[j]) as the last two numbers of a sequence
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                int first = arr[j] - arr[i]; // Expected previous number
                if (first < arr[i] && indexMap.find(first) != indexMap.end()) {
                    int k = indexMap[first]; // Get index of `first`
                    dp[i][j] = dp[k][i] + 1; // Extend sequence length
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }

        return maxLen > 2 ? maxLen : 0; // If no valid sequence, return 0
    }
};
