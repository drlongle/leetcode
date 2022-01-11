class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // Iterative: there are 3 scenarios:
        // 1) If node has right child, level down to the leftmost node and return it.
        // 2) Otherwise if node is his parent's left child, return its parent.
        // 3) Otherwise level up until a node that is its parent's left child or root.
        // If root return nullptr, otherwise return the parent.
        if (node->right)
        {
            node = node->right;
            while (node && node->left)
            {
                node = node->left;
            }
            return node;
        }

        if (node->parent && node->parent->left == node)
        {
            return node->parent;
        }

        while (node->parent && node->parent->right == node)
        {
            node = node->parent;
        }

        return node->parent ? node->parent : nullptr;
    }
};
