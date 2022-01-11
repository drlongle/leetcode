class Solution {
public:
    bool isAncestor(Node* ancestor, Node* child) {
        if (child->parent == NULL) return false;

        if (child->parent == ancestor) {
            return true;
        } else {
            return isAncestor(ancestor, child->parent);
        }
    }

    Node* lowestCommonAncestor(Node* p, Node * q) {

        // root;
        if (p->parent == NULL) return p;
        if (q->parent == NULL) return q;

        if (p == q) return p;

        if (isAncestor(p, q)) return p;
        if (isAncestor(q, p)) return q;

        return lowestCommonAncestor(p->parent, q->parent);
    }
};
