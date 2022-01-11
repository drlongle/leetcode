class Solution {
public:
    int level(Node* r){
        int lvl=0;
        while(r->parent){
            lvl++;
            r=r->parent;
        }
        return lvl;
    }

    Node* lowestCommonAncestor(Node* p, Node * q) {
        int lvlp=level(p),lvlq=level(q);
        if(lvlp>lvlq){
            auto diff=lvlp-lvlq;
            while(diff){
                p=p->parent;
                diff--;
            }
        }
        else{
            auto diff=lvlq-lvlp;
            while(diff){
                q=q->parent;
                diff--;
            }
        }
        if(p==q)
            return p;
        while(p->parent!=q->parent){
            p=p->parent;
            q=q->parent;
        }
        return p->parent;
    }
};
