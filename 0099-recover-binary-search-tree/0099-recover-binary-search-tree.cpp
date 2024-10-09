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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        TreeNode* predecessor = nullptr;

        while (root) {
            if (root->left) {
                // Find the rightmost node in the left subtree or create a temporary link to root
                predecessor = root->left;
                while (predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // Create a temporary link to root and move left
                if (!predecessor->right) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    // Revert the temporary link and check for swapped nodes
                    if (prev && prev->val > root->val) {
                        if (!first) first = prev;
                        second = root;
                    }
                    prev = root;
                    
                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {
                // No left subtree, check for swapped nodes
                if (prev && prev->val > root->val) {
                    if (!first) first = prev;
                    second = root;
                }
                prev = root;
                root = root->right;
            }
        }

        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
