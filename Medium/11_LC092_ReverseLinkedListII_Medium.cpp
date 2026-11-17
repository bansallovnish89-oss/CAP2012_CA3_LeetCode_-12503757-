class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        // Find the node just before the section to reverse.
        ListNode* before = &dummy;
        for (int i = 1; i < left; ++i) {
            before = before->next;
        }

        // Reverse the section one node at a time.
        ListNode* current = before->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* node = current->next;
            current->next = node->next;
            node->next = before->next;
            before->next = node;
        }

        return dummy.next;
    }
};
