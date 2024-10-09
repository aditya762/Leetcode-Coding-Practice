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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Map to store the index of each value in inorder for quick access
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, inorderIndexMap);
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& inorderIndexMap) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr; // Base case
        }
        
        int rootVal = postorder[postEnd]; // The root is the last element in the postorder segment
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndexInOrder = inorderIndexMap[rootVal]; // Find the root's index in the inorder array
        int rightTreeSize = inEnd - rootIndexInOrder; // Calculate the size of the right subtree
        
        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(inorder, postorder, inStart, rootIndexInOrder - 1, postStart, postEnd - rightTreeSize - 1, inorderIndexMap);
        root->right = buildTreeHelper(inorder, postorder, rootIndexInOrder + 1, inEnd, postEnd - rightTreeSize, postEnd - 1, inorderIndexMap);
        
        return root; // Return the constructed tree
    }
};
