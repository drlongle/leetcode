class Solution {
public:
    int getDiameter(Node* root,int &diameter)
    {
        int height{0};
        for(auto&x:root->children)
        {
            int tempHeight=getDiameter(x,diameter);
            diameter=max(diameter,tempHeight+height);
            height=max(tempHeight,height);
        }
        return height+1;
    }
    int diameter(Node* root) {
        if(!root)
            return 0;
        int diameter{0};
        getDiameter(root,diameter);
        return diameter;
    }
};
