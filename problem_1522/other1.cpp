class Solution {
public:
    int m = 0;
    int diameter(Node* root, bool isroot=true) {
        int mx1=0,mx2=0;
        for(int i=0;i<root->children.size();i++){
            int l  = diameter(root->children[i], false);
            if(l>=mx2){
                if(l>=mx1) mx2=mx1, mx1=l;
                else mx2=l;
            }
        }
        m=max(m,mx2+mx1);
        return isroot? max(m, mx2+mx1): mx1+1;
    }
};
