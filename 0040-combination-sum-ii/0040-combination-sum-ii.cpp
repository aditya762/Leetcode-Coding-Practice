class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        std::sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        backtrack(result, combination, candidates, target, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& combination,
                   std::vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                // Skip duplicates
                continue;
            }
            if (candidates[i] > target) {
                // No need to continue if the candidate is greater than the target
                break;
            }
            
            combination.push_back(candidates[i]);
            backtrack(result, combination, candidates, target - candidates[i], i + 1);
            combination.pop_back(); // Backtrack
        }
    }
};