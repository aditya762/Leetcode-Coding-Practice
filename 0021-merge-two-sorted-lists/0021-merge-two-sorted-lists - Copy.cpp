class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to help in easily building the new list
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // While both lists are non-empty, compare and append the smaller node
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Append the remaining nodes of list1 or list2
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // Return the merged list, which starts from dummy's next
        return dummy->next;
    }
};
