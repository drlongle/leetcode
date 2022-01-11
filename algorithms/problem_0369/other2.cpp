class Solution {
public:
    using fun = function<bool(ListNode*)>;
    ListNode* plusOne(ListNode* head) {
        fun go = [&](auto node) {
            if (!node)
                return false;
            auto carry = go(node->next);
            if (carry || !node->next) {
                if (++node->val == 10) {
                    node->val = 0;
                    return true;
                }
            }
            return false;
        };
        if (go(head)) {
            auto pre = new ListNode(1);
            pre->next = head;
            return pre;
        }
        return head;
    }
};
