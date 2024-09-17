class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result; // To store the result
        int n = nums.size();
        
        // Sort the array to help skip duplicates and to use two-pointer technique
        sort(nums.begin(), nums.end());

        // Iterate over the array with two nested loops
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate values for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Two-pointer technique for the remaining two elements
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right]; // Calculate the sum
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Move the left pointer to the next distinct value
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Move the right pointer to the next distinct value
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    // If the sum is less than the target, move the left pointer to increase the sum
                    else if (sum < target) {
                        left++;
                    }
                    // If the sum is greater than the target, move the right pointer to decrease the sum
                    else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};