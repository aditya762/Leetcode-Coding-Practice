class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int n =nums.size();
       int max=INT_MIN;
       int ans = 0;
       for(int i = 0;i<n;i++){
        if(nums[i]>max){
            max=nums[i];
            ans=i;
        }
       }return ans;}
};