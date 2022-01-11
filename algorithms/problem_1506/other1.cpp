class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int root = 0;
        /* All Nodes when we traverse children + themselves occur twice except
         * the root which does not have a parent. So, XOR them all we're left with
         * the root. */
        for (auto node: tree) {
            root ^= node->val;
            for (auto child: node->children)
                root ^= child->val;
        }

        for (auto node: tree)
            if (node->val == root)
                return node;
        return nullptr;
    }
};
