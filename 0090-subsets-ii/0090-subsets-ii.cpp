class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        generateSubsets(0, nums, subset, result);
        return result;
    }
    
    void generateSubsets(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);
        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) continue; // Skip duplicates
            subset.push_back(nums[i]);
            generateSubsets(i + 1, nums, subset, result);
            subset.pop_back();
        }
    }
};
