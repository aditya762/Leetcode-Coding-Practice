/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Pointer to the current node
        ListNode* current = head;

        // Traverse the linked list
        while (current) {
            // While the next node exists and is a duplicate
            while (current->next && current->val == current->next->val) {
                // Skip the next node
                current->next = current->next->next;
            }
            // Move to the next node
            current = current->next;
        }

        return head; // Return the modified list
    }
};

// Example usage:
// ListNode* head = ...; // Construct the linked list
// Solution sol;
// ListNode* result = sol.deleteDuplicates(head); // result will contain the modified list
