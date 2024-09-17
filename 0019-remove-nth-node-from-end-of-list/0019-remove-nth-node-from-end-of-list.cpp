
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node before the head to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize two pointers
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move the fast pointer n+1 steps ahead
        for (int i = 1; i <= n + 1; i++) {
            fast = fast->next;
        }

        // Move both fast and slow pointers together until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Now slow is at the node just before the one to be removed
        ListNode* nodeToRemove = slow->next;
        slow->next = slow->next->next;

        // Delete the removed node
        delete nodeToRemove;

        // Return the new head
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};