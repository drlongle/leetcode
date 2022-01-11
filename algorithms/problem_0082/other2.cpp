ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
    
        ListNode *ans = new ListNode(INT_MIN);
        ans->next = head;
        ListNode *pre = ans;
        
        ListNode *cur = head;
        while(cur)
        {
            int val = cur->val;
            int cnt = 0;
            while(cur->next && val==cur->next->val)
            {
                cur = cur->next;
                cnt++;
            }
            
            if(cnt==0)
            {
                pre->next = cur;
                pre = pre->next;
            }
            
            cur = cur->next;
        }
        pre->next = nullptr;
        return ans->next;
    }

