class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string current, int open_count, int close_count, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open_count < n) {
            backtrack(result, current + '(', open_count + 1, close_count, n);
        }
        
        if (close_count < open_count) {
            backtrack(result, current + ')', open_count, close_count + 1, n);
        }
    }
};
