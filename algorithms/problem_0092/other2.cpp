class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *start = new ListNode(-1);
        start->next = head;
        ListNode *itr = start;
        ListNode *pre_broken;
        ListNode *broken;
        for(int i=0; i<m-1; i++) {
            itr = itr->next;
        }
        pre_broken = itr;
        broken = itr = itr->next;
        ListNode *pre = nullptr;
        for(int i=0; i<=n - m; i++) {
            ListNode *nxt = itr->next;
            itr->next = pre;
            pre = itr;
            itr = nxt;
        }
        pre_broken->next = pre;
        broken->next = itr;
        return start->next;
    }
};

