class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // If the input is empty, return an empty result
        if (digits.empty()) return {};

        // Mapping of digits to corresponding letters (as on a telephone keypad)
        vector<string> phone = {"",    "",    "abc",  "def", 
                                "ghi", "jkl", "mno", "pqrs", 
                                "tuv", "wxyz"};

        vector<string> result;  // To store the combinations
        string current;         // To store the current combination
        backtrack(digits, 0, current, result, phone);  // Start the backtracking process
        return result;
    }

private:
    // Helper function for backtracking
    void backtrack(const string& digits, int index, string& current, 
                   vector<string>& result, const vector<string>& phone) {
        // If the current combination has the same length as the input digits
        if (index == digits.size()) {
            result.push_back(current);  // Add the current combination to the result
            return;
        }

        // Get the digit at the current index
        char digit = digits[index];
        // Find the corresponding letters for the current digit
        const string& letters = phone[digit - '0'];

        // Iterate over the letters for the current digit
        for (char letter : letters) {
            current.push_back(letter);  // Add the letter to the current combination
            backtrack(digits, index + 1, current, result, phone);  // Move to the next digit
            current.pop_back();  // Backtrack by removing the last letter
        }
    }
};