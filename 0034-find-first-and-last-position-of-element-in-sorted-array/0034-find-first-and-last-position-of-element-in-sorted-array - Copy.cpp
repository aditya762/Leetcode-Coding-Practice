class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        if (nums.empty()) return result;

        // Find the starting position of the target
        int start = findPosition(nums, target, true);
        if (start == -1) return result; // If target is not found

        // Find the ending position of the target
        int end = findPosition(nums, target, false);

        result[0] = start;
        result[1] = end;
        return result;
    }

private:
    int findPosition(vector<int>& nums, int target, bool findFirst) {
        int left = 0, right = nums.size() - 1;
        int position = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                position = mid;
                if (findFirst) {
                    right = mid - 1; // Continue to search in the left half
                } else {
                    left = mid + 1; // Continue to search in the right half
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return position;
    }
};
