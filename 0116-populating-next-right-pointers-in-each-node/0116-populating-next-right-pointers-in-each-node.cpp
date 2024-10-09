class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node* current = root; // Start with the root of the tree
        
        while (current->left) { // Since it's a perfect binary tree, we only check left child
            Node* temp = current; // Use temp to traverse the current level
            while (temp) {
                // Connect the left and right child
                temp->left->next = temp->right;
                
                // Connect the right child to the next left child if exists
                if (temp->next) {
                    temp->right->next = temp->next->left;
                }
                
                // Move to the next node in the current level
                temp = temp->next;
            }
            // Move down to the next level
            current = current->left;
        }
        
        return root;
    }
};