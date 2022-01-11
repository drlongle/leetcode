class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> nodes;
        vector<int> res;
        if (!root)
            return res;

        nodes.emplace(root);
        while (nodes.size()) {
            auto node = nodes.top();
            res.push_back(node->val);
            nodes.pop();
            reverse(begin(node->children), end(node->children));
            for (auto child: node->children)
                nodes.emplace(child);
        }

        return res;
    }
};