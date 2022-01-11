class Solution {
    void add(ListNode* root, int & carry){
        if(root == nullptr ) return;
        add(root -> next, carry);
        if( carry){
            if( root ->val +1 == 10){
                root->val = 0;
                carry = 1;
            } else{
                root->val++;
                carry = 0;
            }
        }
    }

public:
    ListNode* plusOne(ListNode* head) {
        int carry = 1;
        add(head,carry);
        if( carry){
            ListNode* temp = new ListNode(1,head);
            head = temp;
        }

        return head;
    }
};
