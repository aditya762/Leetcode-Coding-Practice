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
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to simplify edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;
            
            // Perform the swap
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // Move pointers forward
            prev = first;
            head = first->next;
        }
        
        return dummy.next;
    }
};