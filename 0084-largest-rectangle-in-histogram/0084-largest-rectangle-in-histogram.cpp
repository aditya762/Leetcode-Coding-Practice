class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indices; // Stack to store indices of the histogram bars
        int maxArea = 0; // Variable to keep track of the maximum area
        heights.push_back(0); // Append a height of 0 to ensure all bars are processed

        for (int i = 0; i < heights.size(); i++) {
            // While there are bars in the stack and the current height is less than the height of the bar at the top of the stack
            while (!indices.empty() && heights[i] < heights[indices.top()]) {
                int height = heights[indices.top()]; // Height of the bar to calculate area
                indices.pop(); // Pop the top index

                // Calculate the width
                int width = indices.empty() ? i : i - indices.top() - 1;
                maxArea = max(maxArea, height * width); // Update max area if necessary
            }
            indices.push(i); // Push the current index onto the stack
        }

        return maxArea; // Return the maximum area found
    }
};

// Example usage:
// vector<int> heights = {2, 1, 5, 6, 2, 3};
// Solution sol;
// int area = sol.largestRectangleArea(heights); // area will be 10
