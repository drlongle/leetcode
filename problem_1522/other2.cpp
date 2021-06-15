class Solution {
public:
    int diameter(Node* root) {
        dfs(root);
        return ret;
    }
private:
    int ret = 0;
    int dfs(Node* root) {
        if(!root) return 0;
        int top1 = 0, top2 = 0;
        for(Node* e :root->children) {
            int tmp = dfs(e);
            if(tmp > top1) {
                top2 = top1;
                top1 = tmp;
            } else if(tmp > top2) top2 = tmp;
        }
        ret = max(ret, top2 + top1);
        return top1 + 1;
    }
};
