/*
* Intuition
Scan from the left, and calculate the prefix sum.
Whenever meet the seen prefix,
remove all elements of the subarray between them.

* Explanation
Because the head ListNode can be removed in the end,
I create a dummy ListNode and set it as a previous node of head.
prefix calculates the prefix sum from the first node to the current cur node.

Next step, we need an important hashmap m (no good name for it),
It takes a prefix sum as key, and the related node as the value.

Then we scan the linked list, accumulate the node's value as prefix sum.

1. If it's a prefix that we've never seen, we set m[prefix] = cur.
2. If we have seen this prefix, m[prefix] is the node we achieve this prefix sum.
   We want to skip all nodes between m[prefix] and cur.next (exclusive).
   So we simplely do m[prefix].next = cur.next.
We keep doing these and it's done.
*/

ListNode* removeZeroSumSublists(ListNode* head)
{
    ListNode dummy(0), *cur = &dummy;
    dummy.next = head;
    int prefix = 0;
    unordered_map<int, ListNode*> m;
    while (cur) {
        prefix += cur->val;
        if (m.count(prefix)) {
            cur = m[prefix]->next;
            int p = prefix + cur->val;
            while (p != prefix) {
                m.erase(p);
                cur = cur->next;
                p += cur->val;
            }
            m[prefix]->next = cur->next;
        } else {
            m[prefix] = cur;
        }
        cur = cur->next;
    }
    return dummy.next;
}
