class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        while (fast && n >= 1) {
            fast = fast->next;
            --n;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy.next;;
    }
};
