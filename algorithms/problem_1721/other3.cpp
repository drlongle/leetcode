class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *A = head, *B = head, *nodeK;
        for (int i = 1; i < k; i++) A = A->next;
        nodeK = A, A = A->next;
        while (A) A = A->next, B = B->next;
        swap(nodeK->val, B->val);

        return head;
    }
};
