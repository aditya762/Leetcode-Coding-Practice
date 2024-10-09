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
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
    
    int height(TreeNode* node) {
        if (!node) return 0; // Base case: height of an empty tree is 0
        
        // Recursively get the height of the left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        // If left or right subtree is unbalanced, return -1
        if (leftHeight == -1 || rightHeight == -1) return -1;
        
        // If the current node is unbalanced, return -1
        if (abs(leftHeight - rightHeight) > 1) return -1;
        
        // Return the height of the tree rooted at the current node
        return max(leftHeight, rightHeight) + 1;
    }
};
