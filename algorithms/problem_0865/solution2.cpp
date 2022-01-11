struct Entry {
    TreeNode* node;
    vector<TreeNode*> path;
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        array<vector<Entry>, 2> rows;
        Entry e{root, vector<TreeNode*>{root}};
        rows[0].emplace_back(e);
        int curr = 0, next;

        while (!rows[curr].empty()) {
            next = 1 - curr;
            rows[next].clear();
            for (auto& e: rows[curr]) {
                if (!e.node->left && !e.node->right)
                    continue;
                Entry new_e(e);
                for (auto child : {e.node->left, e.node->right}) {
                    if (child) {
                        new_e.node = child;
                        new_e.path.emplace_back(child);
                        rows[next].emplace_back(new_e);
                        new_e.path.pop_back();
                    }
                }
            }
            curr = next;
        }

        next = 1 - curr;
        if (rows[next].empty())
            abort();
        TreeNode* candidate = root;
        size_t path_len = rows[next][0].path.size();
        size_t row_size = rows[next].size();
        if (row_size == 1)
            return rows[next][0].path[path_len-1];
        for (size_t i = 1; i < path_len-1; ++i) {
            bool match = true;
            for (size_t j = 1; match && j < row_size; ++j) {
                if (rows[next][0].path[i] != rows[next][j].path[i])
                    match = false;
            }
            if (match)
                candidate = rows[next][0].path[i];
            else
                break;
        }

        return candidate;
    }
};
