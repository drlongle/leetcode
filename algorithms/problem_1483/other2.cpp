/*
Jump array is a logarithmic data structure. For each node, it stores 1st, 2nd, 4th, 8th and so on ancestors.

First, we convert the input to some tree structure. Then, we traverse the tree,
passing the whole path to from the current node to the root. Then, we add logarithmic
ancestors to the jump array of the node i.

For the query, we find the furthers jump we can make, and then maximum possible recursive
jumps until we reach our destination.

Note that we store levels for each node, so we can immediately tell if k is too big.
*/
class TreeAncestor
{
public:
    vector<vector<int>> jumps;
    vector<int> lvls;
    void traverse(vector<int> &path, vector<vector<int>> &tree, int i, int l)
    {
        lvls[i] = l;
        for (int p = 1; p <= path.size(); p <<= 1)
            jumps[i].push_back(path[path.size() - p]);
        path.push_back(i);
        for (auto ch : tree[i])
            traverse(path, tree, ch, l + 1);
        path.pop_back();
    }
    TreeAncestor(int n, vector<int> &parent)
    {
        vector<vector<int>> tree(n);
        jumps = vector<vector<int>>(n);
        lvls = vector<int>(n);
        for (auto i = 1; i < n; ++i)
            tree[parent[i]].push_back(i);
        traverse(vector<int>() = {}, tree, 0, 0);
    }
    int getKthAncestor(int node, int k)
    {
        if (k == 0)
            return node;
        if (lvls[node] < k)
            return -1;
        auto p = 1, pos = 0;
        while ((p << 1) <= k)
        {
            p <<= 1;
            ++pos;
        }
        return getKthAncestor(jumps[node][pos], k - p);
    }
};