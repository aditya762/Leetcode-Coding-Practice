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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Calculate the length of the linked list
        ListNode* curr = head;
        int length = 1;
        while (curr->next) {
            curr = curr->next;
            length++;
        }

        // Connect the last node to the head to form a circle
        curr->next = head;

        // Calculate the number of steps to move to the new head
        k = k % length;
        int stepsToNewHead = length - k;

        // Find the new tail node (which will be stepsToNewHead steps from the original head)
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        // Break the circle and set the new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
