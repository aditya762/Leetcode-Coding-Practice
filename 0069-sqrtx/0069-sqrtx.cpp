class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1, right = x, result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid*mid is less than or equal to x
            if (mid <= x / mid) {
                result = mid; // mid is a valid square root candidate
                left = mid + 1; // Search for a larger value in the right half
            } else {
                right = mid - 1; // Search for a smaller value in the left half
            }
        }
        
        return result;
    }
};
