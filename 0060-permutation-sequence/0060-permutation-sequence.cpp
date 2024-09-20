class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int factorial = 1;
        
        for (int i = 1; i < n; ++i) {
            factorial *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k--; // Convert to 0-based index
        
        string result;
        
        while (!nums.empty()) {
            int index = k / factorial;
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            
            k %= factorial;
            if (!nums.empty()) {
                factorial /= nums.size();
            }
        }
        
        return result;
    }
};
