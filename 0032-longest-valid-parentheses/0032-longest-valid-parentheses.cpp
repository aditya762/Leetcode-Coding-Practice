class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int n = s.length();
        stack<int> stk;
        stk.push(-1); // Initialize stack with a base index
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i); // Push the index of '('
            } else {
                stk.pop(); // Pop the stack
                if (stk.empty()) {
                    stk.push(i); // Push the current index as base for future valid substrings
                } else {
                    maxLen = max(maxLen, i - stk.top()); // Calculate the length of valid substring
                }
            }
        }
        
        return maxLen;
    }
};
