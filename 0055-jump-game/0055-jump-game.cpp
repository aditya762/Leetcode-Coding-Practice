class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // The farthest index that can be reached
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false;  // If current index is beyond max reachable, return false
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) return true;  // If we can reach or exceed the last index, return true
        }

        return false;
    }
};
