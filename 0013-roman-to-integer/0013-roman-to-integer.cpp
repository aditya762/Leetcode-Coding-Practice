class Solution {
public:
    int romanToInt(string s) {
        // Map of Roman numerals and their integer values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        int n = s.size();
        
        // Loop through the string
        for (int i = 0; i < n; i++) {
            // If the current symbol is smaller than the next one, subtract it
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            } 
            // Otherwise, add the value
            else {
                result += roman[s[i]];
            }
        }
        
        return result;
    }
};
