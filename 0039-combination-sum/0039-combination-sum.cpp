class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(result, combination, candidates, target, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& combination,
                   vector<int>& candidates, int target, int start) {
        if (target == 0) {
            // Found a valid combination
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue; // Skip if the candidate exceeds the target
            
            combination.push_back(candidates[i]); // Choose the candidate
            // Recursively try to find the remaining combination
            backtrack(result, combination, candidates, target - candidates[i], i);
            combination.pop_back(); // Backtrack
        }
    }
};
