class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // Return empty string if input is empty
        
        // Use the first string as a base for comparison
        string prefix = strs[0];
        
        // Iterate through the rest of the strings
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            // Compare characters of the prefix and the current string
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                j++;
            }
            // Reduce the prefix to the matched portion
            prefix = prefix.substr(0, j);
            
            // If at any point the common prefix is empty, return ""
            if (prefix.empty()) return "";
        }
        
        return prefix;
    }
};
