class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root) {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> cloned_nodes;
        cloned_nodes[root] = new Node{root->val};
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            for (Node* adj:n->children) {
                if (cloned_nodes.find(adj) == cloned_nodes.end()) {
                    cloned_nodes[adj] = new Node{adj->val};
                    cloned_nodes[n]->children.push_back(cloned_nodes[adj]);
                    q.push(adj);
                } else {
                    cloned_nodes[n]->children.push_back(cloned_nodes[adj]);
                }
            }
        }

        return cloned_nodes[root];
    }
};
