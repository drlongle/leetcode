class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (head) {
            int val = head->val;
            if (head->next && head->next->val == val) {
                while (head && head->val == val)
                    head = head->next;
                continue;
            } 

            tail->next = head;
            tail = head;
            head = head->next;
        }
        tail->next = nullptr;
        
        return dummy.next;
    }
};
