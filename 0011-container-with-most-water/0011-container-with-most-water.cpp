class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        // Use two pointers, one starting at the beginning and one at the end
        while (left < right) {
            // Calculate the area formed by the lines at positions left and right
            int currentArea = (right - left) * min(height[left], height[right]);
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
