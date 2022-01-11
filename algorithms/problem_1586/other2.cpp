class BSTIterator
{
public:
    BSTIterator(TreeNode* root)
    {
        for (; root; root = root->left)
            nexts.push({root, true});
    }

    bool hasNext()
    {
        return !nexts.empty();
    }

    int next()
    {
        auto [next, push] = nexts.top();
        nexts.pop();

        for (auto n = next->right; push && n; n = n->left)
            nexts.push({n, true});

        prevs.push(next);
        return next->val;
    }

    bool hasPrev()
    {
        return prevs.size() > 1;
    }

    int prev()
    {
        nexts.push({ prevs.top(), false });
        prevs.pop();

        return prevs.top()->val;
    }

private:
    stack<TreeNode*> prevs;
    stack<pair<TreeNode*, bool>> nexts;
};
