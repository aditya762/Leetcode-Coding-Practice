class Solution {
public:
    int minLength(string s) {
        stack<char> stack;

        // Iterate over each character in the input string
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];

            // If the stack is empty, simply push the current character
            if (stack.empty()) {
                stack.push(currentChar);
                continue;
            }

            // Check for "AB" pattern, remove the pair by popping from the stack
            if (currentChar == 'B' && stack.top() == 'A') {
                stack.pop();
            }
            // Check for "CD" pattern, remove the pair by popping from the stack
            else if (currentChar == 'D' && stack.top() == 'C') {
                stack.pop();
            }
            // Otherwise, push the current character onto the stack
            else {
                stack.push(currentChar);
            }
        }

        return stack.size();
    }
};