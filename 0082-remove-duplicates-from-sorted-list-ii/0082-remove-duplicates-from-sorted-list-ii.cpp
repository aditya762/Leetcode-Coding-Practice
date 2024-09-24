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
        // Create a dummy node to simplify edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (head) {
            // Check for duplicates
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // Link previous non-duplicate node to the next distinct node
                prev->next = head->next;
            } else {
                // Move the previous pointer only if no duplicates
                prev = prev->next;
            }
            head = head->next; // Move to the next node
        }
        return dummy.next; // Return the modified list
    }
};

// Example usage:
// ListNode* head = ...; // Construct the linked list
// Solution sol;
// ListNode* result = sol.deleteDuplicates(head); // result will contain the modified list
