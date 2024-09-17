class Solution {
public:
    bool isValid(string s) {
        // Stack to store opening brackets
        stack<char> stk;
        
        // Map to match closing brackets with corresponding opening ones
        unordered_map<char, char> matchingBrackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for (char ch : s) {
            // If the character is an opening bracket, push it onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            }
            // If the character is a closing bracket, check for its match
            else {
                // If stack is empty or top of the stack doesn't match the closing bracket
                if (stk.empty() || stk.top() != matchingBrackets[ch]) {
                    return false;
                }
                // Pop the matching opening bracket
                stk.pop();
            }
        }
        
        // If the stack is empty, all brackets matched properly
        return stk.empty();
    }
};