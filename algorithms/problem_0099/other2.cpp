/*
The solution is based on idea that I visit tree in sorted order. And starting from the time point when
I encounter with first not sorted item I found TreeNode with minimum value to swap if after with first
not sorted item.

Example, let's have a look at TreeNodes visited in sorted order
1 3 7 5 4
7 - item to swap
4 - minimum item after 7
 */

class Solution {
public:
    using Node = TreeNode;
    void recoverTree(TreeNode* root) {
        Node* prev = nullptr;
        Node* first_not_sorted = nullptr;
        Node* min_node = nullptr;
        bool is_sorted = true;
        function<void(Node*)> visit_sorted;
        visit_sorted = [&](Node* node) {
            if (!node) return;
            visit_sorted(node->left);
            if (!prev) {
                prev = node;
            }
            else if (prev->val > node->val && is_sorted) {
                is_sorted = false;
                first_not_sorted = prev;
                min_node = node;
            }
            prev = node;
            if (!is_sorted) {
                if (min_node->val > node->val) {
                    min_node = node;
                }
            }
            visit_sorted(node->right);
        };
        visit_sorted(root);
        swap(min_node->val, first_not_sorted->val);
    }
};