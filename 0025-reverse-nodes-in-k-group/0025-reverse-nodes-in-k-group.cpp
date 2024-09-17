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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }
        
        curr = head;
        while (count >= k) {
            ListNode* groupStart = curr;
            ListNode* prev = nullptr;
            ListNode* temp = nullptr;
            
            // Reverse k nodes
            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            // Connect reversed group with the previous part
            prevGroupEnd->next = prev;
            groupStart->next = curr;
            
            // Move prevGroupEnd to the end of the reversed group
            prevGroupEnd = groupStart;
            
            // Reduce the count
            count -= k;
        }
        
        return dummy->next;
    }
};