class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);  // To store the heights of the histogram at each row
        int maxArea = 0;
        
        // Loop through each row to build the histogram and calculate the max rectangle area
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;  // Increase the height for '1'
                } else {
                    heights[j] = 0;  // Reset the height for '0'
                }
            }
            // Calculate max area for the current row's histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }
    
    // Helper function to calculate the largest rectangle in a histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);  // Add a sentinel value to make sure we calculate all areas
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};
