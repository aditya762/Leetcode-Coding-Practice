class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount.reserve(nums.size()); // Prevents rehashing for small arrays
        
        int count = 0, sum = 0;
        prefixSumCount[0] = 1;
        
        for (int num : nums) {
            sum += num;
            int target = sum - k;
            if (prefixSumCount.count(target)) {
                count += prefixSumCount[target];
            }
            prefixSumCount[sum]++;
        }
        
        return count;
    }
};