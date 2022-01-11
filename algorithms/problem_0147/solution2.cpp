struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res = new ListNode();
        ListNode *curr = head;
        
        while (curr) {
            auto next = curr->next;
            curr->next = nullptr;
            
            auto it = res;
            while (it && it->next && it->next->val < curr->val)
                it = it->next;
            curr->next = it->next;
            it->next = curr;
            curr = next;
        }
        
        return res->next;
    }
};
