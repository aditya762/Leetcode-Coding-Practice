class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(), nums.end());
       int a = n/2; 
       int b = nums[a];
       return b;
    }
};