struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr = head;
    
    while( curr != NULL)
    {
        for(struct ListNode* cequal = curr->next; cequal != NULL; cequal = cequal->next)
        {
            if(cequal->val == curr->val)
            {
                curr->next = cequal->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

