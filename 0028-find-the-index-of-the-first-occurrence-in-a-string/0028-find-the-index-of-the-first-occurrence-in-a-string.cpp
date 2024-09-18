class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        if (n == 0) return 0; // If needle is empty, return 0
        
        for (int i = 0; i <= m - n; i++) {
            if (haystack.substr(i, n) == needle) {
                return i; // Return the index where needle starts
            }
        }
        
        return -1; // If needle is not found
    }
};
