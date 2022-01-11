void connect(TreeLinkNode *root) {
        if (!root) return ;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            TreeLinkNode* prev = nullptr;
            while (size--) {
                if (q.front()->right) q.push(q.front()->right);
                if (q.front()->left) q.push(q.front()->left);
                q.front()->next = prev;
                prev = q.front();
                q.pop();
            }
        }
    }

