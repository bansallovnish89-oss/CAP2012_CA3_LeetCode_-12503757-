class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // Save the rest of the list
            curr->next = prev;               // Reverse this link
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};
