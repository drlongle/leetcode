class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        m_head = head;
        len = 0;
        while (head) {
            head = head->next;
            ++len;
        }
    }
    
    ListNode* m_head;
    int len;
    
    /** Returns a random node's value. */
    int getRandom() {
        int index = random() % len;
        ListNode* node = m_head;
	while (index > 0) {
            --index;
            node = node->next;
	}

        return node->val;
    }
};
