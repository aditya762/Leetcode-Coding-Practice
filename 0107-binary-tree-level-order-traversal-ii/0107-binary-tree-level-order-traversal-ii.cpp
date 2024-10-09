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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result; // To store the final result
        if (!root) return result; // If the tree is empty, return empty result
        
        queue<TreeNode*> q; // Queue for BFS
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size(); // Number of nodes at the current level
            vector<int> currentLevel; // To store nodes of the current level
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); // Get the front node
                q.pop(); // Remove it from the queue
                
                currentLevel.push_back(node->val); // Add the node's value to current level
                
                // Add child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Insert current level at the beginning of the result
            result.insert(result.begin(), currentLevel);
        }
        
        return result; // Return the bottom-up level order traversal
    }
};
