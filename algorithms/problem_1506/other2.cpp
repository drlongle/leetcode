class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        long long ret = 0;
        // sizeof(Node*) == 8 because it's 64 bit system.
        for(auto x : tree) {
            ret ^= (long long) x;
            for(auto y : x->children)
                ret ^= (long long) y;
        }
        return (Node*) ret;
    }
};
