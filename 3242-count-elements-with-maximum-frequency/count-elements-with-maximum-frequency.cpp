class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> freq;
    int maxFreq = 0, count = 0;
      for (int n : nums){
        freq[n]++;
        maxFreq=max(maxFreq, freq[n]);
      }  
      for(auto& [key, value]:freq){
        if(value==maxFreq){
            count+=value;
        }


      }
      return count;
    }
};