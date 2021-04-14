class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1, dummy2;
        ListNode* tail1 = &dummy1, *tail2 = &dummy2, *prev;
        while (head) {
            if (head->val < x) {
                tail1->next = head;
                tail1 = head;
            } else {
                tail2->next = head;
                tail2 = head;
            }
            prev = head;
            head = head->next;
            prev->next = nullptr;
        }
        tail1->next = dummy2.next;

        return dummy1.next;
    }
};