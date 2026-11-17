class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Find the length and the current tail.
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            ++length;
        }

        k %= length;
        if (k == 0) {
            return head;
        }

        // Form a circle.
        tail->next = head;

        // Find the new tail, then break the circle.
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
