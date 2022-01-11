class Solution {
public:
    int diameter(Node* root) {
        if (!root) return 0;

        std::unordered_map<Node*, int> nodeToDepth {};
        int diameter = 0;
        std::stack<Node*> s {};
        s.push(root);
        while (!s.empty()) {
            Node *node = s.top();
            bool isReady = true;
            for (Node* n : node->children) {
                if (nodeToDepth.find(n) == nodeToDepth.end()) {
                    s.push(n); isReady = false;
                    break;
                }
            }
            if (isReady) {
                s.pop();
                int m1 = 0, m2 = 0;
                for (Node* n : node->children) {
                    if (nodeToDepth[n] > m1) {
                        m2 = m1;
                        m1 = nodeToDepth[n];
                    } else if (nodeToDepth[n] > m2) {
                        m2 = nodeToDepth[n];
                    }
                }
                nodeToDepth[node] = m1+1;
                diameter = std::max(diameter, m1+m2);
            }
        }

        return diameter;
    }
};
