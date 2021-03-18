class Solution {
public:
    void check_vals(int &index,const vector<int> &preorder,int max_val,int min_val){
        if(index==preorder.size() || preorder[index]>max_val || preorder[index]<min_val) return;
        int val=preorder[index];
        ++index;
        check_vals(index,preorder,val,min_val);
        check_vals(index,preorder,max_val,val);
    }

    bool verifyPreorder(vector<int>& preorder) {
        int index=0;
        check_vals(index,preorder,INT_MAX,INT_MIN);
        return (index==preorder.size());
    }
};
