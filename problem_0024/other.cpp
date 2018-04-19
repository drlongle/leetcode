/*
Pointer-pointer pp points to the pointer to the current node. So at first, pp points to head, and later it points to the next field of ListNodes. Additionally, for convenience and clarity, pointers a and b point to the current node and the next node.

We need to go from *pp == a -> b -> (b->next) to *pp == b -> a -> (b->next). The first three lines inside the loop do that, setting those three pointers (from right to left). The fourth line moves pp to the next pair.
*/

ListNode* swapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}

