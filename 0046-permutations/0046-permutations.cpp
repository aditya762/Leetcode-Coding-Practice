class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
        // Base case: if start index reaches the end, add current permutation to result
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        // Generate permutations by swapping the current element with all subsequent elements
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]); // Swap current element with element at position i
            backtrack(nums, result, start + 1); // Recurse for the next element
            swap(nums[start], nums[i]); // Swap back to backtrack and restore original state
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; // To store all permutations
        backtrack(nums, result, 0); // Start backtracking from index 0
        return result;
    }
};
