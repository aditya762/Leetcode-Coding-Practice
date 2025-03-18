class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }

    int search(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return search(nums, target, left, mid - 1);
        else return search(nums, target, mid + 1, right);
    }
};
