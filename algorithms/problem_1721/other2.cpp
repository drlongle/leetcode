class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        auto first = head;
        k--;
        while(k--) first = first -> next;
        auto fast = first;
        auto second = head;
        while(fast -> next){
            fast = fast -> next;
            second = second -> next;
        }
        swap(first -> val, second -> val);

        return head;
    }
};