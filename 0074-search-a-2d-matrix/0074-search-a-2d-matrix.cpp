class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false; // Check for empty matrix
        
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1; // Binary search bounds

        while (left <= right) {
            int mid = left + (right - left) / 2; // Find the mid index
            int midValue = matrix[mid / n][mid % n]; // Convert 1D index to 2D indices

            if (midValue == target) {
                return true; // Target found
            } else if (midValue < target) {
                left = mid + 1; // Search right half
            } else {
                right = mid - 1; // Search left half
            }
        }

        return false; // Target not found
    }
};
