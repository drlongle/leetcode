class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        // using queue
        unordered_set<Node*> visited;
        queue<Node*> que;
        que.push(p);
        que.push(q);

        while (que.size()){
            Node* cur = que.front();
            que.pop();
            if (visited.find(cur) != visited.end())
                return cur;

            visited.insert(cur);
            // do not check if it is in visited already
            // since we need the duplicate to decide if it is a common parent
            if (cur -> parent)
                que.push(cur -> parent);
        }
        return p;
    }
};
