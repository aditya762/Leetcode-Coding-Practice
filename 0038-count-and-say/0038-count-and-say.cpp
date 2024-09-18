class Solution {
public:
    string countAndSay(int n) {
        // Base case
        string result = "1";
        
        for (int i = 1; i < n; ++i) {
            string next_result;
            int j = 0;
            
            while (j < result.size()) {
                char current_char = result[j];
                int count = 0;
                
                // Count consecutive characters
                while (j < result.size() && result[j] == current_char) {
                    ++j;
                    ++count;
                }
                
                // Append the count and character to the next_result
                next_result += to_string(count) + current_char;
            }
            
            // Update result
            result = next_result;
        }
        
        return result;
    }
};
