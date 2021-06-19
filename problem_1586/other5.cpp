class BSTIterator {
public:
    TreeNode *root;
    stack<TreeNode*> st;
    vector<int> visited;
    int pos = -1;

    BSTIterator(TreeNode* root) {
        this->root = root;
    }

    bool hasNext() {
        return pos < (visited.size() -1) || st.size() || root;
    }

    int next() {
        if (pos < visited.size()-1) {
            return visited[++pos]; //if pos is usable for next
        }
        // standard inorder traversal using stack
        while(root || st.size()) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                int res = root->val;
                root = root->right;

                visited.push_back(res); pos++; // save visited values for prev() to use

                return res;
            }
        }

        return 0; // won't reach here
    }

    bool hasPrev() {
        return pos > 0;
    }

    int prev() {
        return visited[--pos]; // if pos is usable for prev
    }
};
