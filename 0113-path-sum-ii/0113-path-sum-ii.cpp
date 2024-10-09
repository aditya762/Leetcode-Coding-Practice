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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;  // To store the result paths
        vector<int> currentPath;      // To store the current path
        findPaths(root, targetSum, currentPath, result); // Start DFS
        return result;
    }
    
    void findPaths(TreeNode* node, int remainingSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) return; // Base case: if the node is null, return
        
        // Add the current node's value to the path
        currentPath.push_back(node->val);
        
        // Check if it's a leaf node and if the path sums to targetSum
        if (!node->left && !node->right && remainingSum == node->val) {
            result.push_back(currentPath); // Store the current path
        } else {
            // Recursively check left and right children
            findPaths(node->left, remainingSum - node->val, currentPath, result);
            findPaths(node->right, remainingSum - node->val, currentPath, result);
        }
        
        // Backtrack: remove the current node's value from the path
        currentPath.pop_back();
    }
};