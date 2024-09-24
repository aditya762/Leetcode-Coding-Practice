class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size(); // Handle cases where size is 2 or less

        int k = 2; // Start from index 2 since we can always keep the first two elements

        for (int i = 2; i < nums.size(); i++) {
            // Check if the current element is different from the last two unique elements
            if (nums[i] != nums[k - 2]) {
                nums[k++] = nums[i]; // Place the current element in the next position
            }
        }
        
        // The first k elements will be the result
        return k;
    }
};

// Example usage:
// Solution sol;
// vector<int> nums = {1, 1, 1, 2, 2, 3};
// int k = sol.removeDuplicates(nums);
// Now nums contains the first k elements which are the desired output.
