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
    void flatten(TreeNode* root) {
        if (!root) return; // Base case: if the node is null, return
        
        // Flatten the left and right subtrees
        flatten(root->left);
        flatten(root->right);
        
        // Store the right subtree
        TreeNode* tempRight = root->right;
        
        // Move the left subtree to the right
        root->right = root->left;
        root->left = nullptr; // Set the left child to null
        
        // Find the end of the new right subtree
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }
        
        // Attach the original right subtree to the end of the new right subtree
        current->right = tempRight;
    }
};