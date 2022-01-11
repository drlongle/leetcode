class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head), *fast = &dummy, *slow = &dummy;
        while (fast) {
            fast = fast->next;
            if (n-- < 0) slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummy.next;
    }
};
