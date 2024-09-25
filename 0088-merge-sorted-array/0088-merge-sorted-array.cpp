class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // Pointer to the last element in nums1 (excluding the extra zeros)
        int j = n - 1;  // Pointer to the last element in nums2
        int k = m + n - 1;  // Pointer to the last position in nums1 (including the extra zeros)
        
        // Start merging from the back of the arrays
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // If there are remaining elements in nums2, place them in nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
