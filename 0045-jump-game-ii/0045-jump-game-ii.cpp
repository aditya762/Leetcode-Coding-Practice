class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; // Already at the last index

        int jumps = 0;
        int current_end = 0; // End of the range for the current jump
        int farthest = 0;    // Farthest position we can reach

        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest we can reach
            farthest = max(farthest, i + nums[i]);

            // When we reach the end of the current jump range
            if (i == current_end) {
                ++jumps;           // Increase jump count
                current_end = farthest; // Move to the farthest point
                if (current_end >= n - 1) break; // If we can reach the end, exit loop
            }
        }
        
        return jumps;
    }
};
