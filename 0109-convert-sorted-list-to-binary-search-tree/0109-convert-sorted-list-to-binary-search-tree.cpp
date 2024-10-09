/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    TreeNode* sortedListToBST(ListNode* head) {
        // Base case
        if (!head) return nullptr;
        
        // Get the size of the linked list
        int size = 0;
        ListNode* current = head;
        while (current) {
            size++;
            current = current->next;
        }
        
        // Recursively build the BST
        return sortedListToBST(head, 0, size - 1);
    }
    
    TreeNode* sortedListToBST(ListNode*& head, int left, int right) {
        if (left > right) return nullptr; // Base case
        
        int mid = left + (right - left) / 2; // Find the middle index
        
        // Recursively build the left subtree
        TreeNode* leftChild = sortedListToBST(head, left, mid - 1);
        
        // Create a new TreeNode with the current head value
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild; // Set left child
        
        // Move to the next node in the linked list
        head = head->next; 
        
        // Recursively build the right subtree
        root->right = sortedListToBST(head, mid + 1, right);
        
        return root; // Return the root of the BST
    }
};
