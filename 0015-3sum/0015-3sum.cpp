class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        // Step 2: Iterate through the array
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate elements for the first element of the triplet
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Two-pointer approach for the remaining part of the array
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element of the triplet
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    // Skip duplicates for the third element of the triplet
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    
                    // Move both pointers inward
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;  // If sum is less than zero, move left pointer to increase the sum
                } else {
                    --right;  // If sum is greater than zero, move right pointer to decrease the sum
                }
            }
        }
        
        return result;
    }
};
