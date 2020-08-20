class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head)return;
        ListNode pre(-1);pre.next=NULL;
        unordered_map<int,ListNode*>m;
        int l=0,r=0;
        for(int i=0;head!=NULL;i++){
            m.insert(pair<int,ListNode*>(i,head));
            head=head->next;
            r=i;
        }
        ListNode*p=&pre;
        int counter=0;
        while(l-1<r){
            if(0==counter%2)p->next=m[l++];
            else p->next=m[r--];
            p=p->next;counter++;
        }
        p->next=NULL;
        head=pre.next;
    }
};

