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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each value in inorder for quick access
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inorderIndexMap);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& inorderIndexMap) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr; // Base case
        }
        
        int rootVal = preorder[preStart]; // The root is the first element in the preorder segment
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndexInOrder = inorderIndexMap[rootVal]; // Find the root's index in the inorder array
        int leftTreeSize = rootIndexInOrder - inStart; // Calculate the size of the left subtree
        
        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize, inStart, rootIndexInOrder - 1, inorderIndexMap);
        root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd, rootIndexInOrder + 1, inEnd, inorderIndexMap);
        
        return root; // Return the constructed tree
    }
};
