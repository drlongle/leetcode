class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        stack<ListNode*> s;
        ListNode* it = head,*high;
        while (it) {
            s.push(it);    
            it = it->next;
        }
        int n = s.size();
        it = head;
        int border = (n-1)/2;
        for (int i = 0;i<border;i++) {
            high = s.top();
            s.pop();
            high->next = it->next;
            it = it->next = high;
            it = it->next;
        }
        if (n%2)
            it->next = nullptr;
        else 
            it->next->next = nullptr;
    }
};

