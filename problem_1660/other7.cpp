class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        // since wrong pointer points to the right
        // it will be in the queue
        // deque<current_node, parent_node>
        deque<pair<TreeNode*, TreeNode*>> que;
        if (!root)
            return nullptr;

        que.push_back(make_pair(root, nullptr));
        pair<TreeNode*, TreeNode*> cur;

        while(que.size()){
            cur = que.front();
            que.pop_front();

            if (cur.first -> left)
                que.push_back(make_pair(cur.first -> left, cur.first));
            if (cur.first -> right){
                bool find_wrong = false;
                for (auto pp : que){
                    if (pp.first == cur.first -> right){
                        find_wrong = true;
                        break;
                    }
                }
                if (find_wrong)
                    break;
                que.push_back(make_pair(cur.first -> right, cur.first));
            }
        }

        if (cur.second -> left == cur.first)
            cur.second -> left = nullptr;
        else
            cur.second -> right = nullptr;

        return root;
    }
};
