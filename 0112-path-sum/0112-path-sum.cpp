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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // If the tree is empty
        if (!root) return false;

        // Subtract the current node's value from targetSum
        targetSum -= root->val;

        // If we reach a leaf node, check if targetSum is 0
        if (!root->left && !root->right) {
            return targetSum == 0;
        }

        // Recursively check the left and right subtree
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
