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
    int minDepth(TreeNode* root) {
        if (!root) return 0; // Base case: if the tree is empty
        
        // If left child is null, only explore the right subtree
        if (!root->left) return minDepth(root->right) + 1;
        
        // If right child is null, only explore the left subtree
        if (!root->right) return minDepth(root->left) + 1;
        
        // If both children exist, find the minimum depth of both subtrees
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
