class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> q;
        stack<TreeNode*> s;
        while(root || s.size()) {
            if (root) {
                s.push(root);
                root=root->left;
            } else {
                root=s.top();
                s.pop();
                q.push_back(root->val);
                if (q.size()>k) {
                    if (q.front()>target && q.back()>target) {
                        q.pop_back();
                        break;
                    } else if (q.front()<target && q.back()<target) {
                        q.pop_front();
                    } else {
                        if (fabs(target-q.front())>fabs(target-q.back())) q.pop_front();
                        else {
                            q.pop_back();
                            break;
                        }
                    }
                }
                root=root->right;
            }
        }
        vector<int> ret(q.begin(), q.end());
        return ret;
    }
};
