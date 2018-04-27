struct ListNode* rotateRight(struct ListNode* head, int k) {   
    //some basic checks
    if(head==NULL || k==0 || head->next == NULL) return head;
    
    struct ListNode *walk=head,*prev;
    int length=1; 
    
    //convert to a circular list
    while(walk->next != NULL){
        walk = walk->next;
        length++;
    }
    prev = walk;
    walk->next = head;    
    walk = head;
    
    //change problem to left rotate by k places
    k = length - (k % length);

    //make the rotation on circular list
    for(int i=0;i<k;i++){
       prev = walk;
       walk=walk->next;        
    }
    //convert back to linear list
    head = walk;
    prev->next = NULL;
    
    return head;
}

