class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize closestSum with the sum of the first three elements

        // Iterate through each number in the array
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            // Two-pointer technique to find the closest sum for the current element nums[i]
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // If the current sum equals the target, return it directly
                if (currentSum == target) {
                    return currentSum;
                }

                // If the current sum is closer to the target, update closestSum
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                // Move pointers to get a sum closer to the target
                if (currentSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return closestSum; // Return the closest sum found
    }
};
