class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int cnt = 1;
        ListNode* p = head, *res;
        while(p){
            if(rand() % cnt == 0) res = p;
            p = p->next;
            cnt++;
        }
        return res->val;
    }
};

