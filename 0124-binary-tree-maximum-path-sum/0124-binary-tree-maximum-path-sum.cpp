/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;  // Initialize to minimum integer value
        maxPathDown(root, maxSum);
        return maxSum;
    }

private:
    int maxPathDown(TreeNode* node, int& maxSum) {
        if (!node) return 0;  // Base case: if the node is null, return 0

        // Calculate the maximum path sum starting from left and right children
        int leftMax = std::max(maxPathDown(node->left, maxSum), 0);  // Ignore negative sums
        int rightMax = std::max(maxPathDown(node->right, maxSum), 0); // Ignore negative sums

        // Update the maximum path sum including the current node
        maxSum = std::max(maxSum, node->val + leftMax + rightMax);

        // Return the maximum path sum "starting" from the current node
        return node->val + std::max(leftMax, rightMax);
    }
};