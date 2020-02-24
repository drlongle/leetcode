/*
Note: Only counting the number of parents does not work, e.g.
if there are orphans or cycles, e.g. [-1,2-1][-1,-1,1] or [1, 0, 3, -1] [-1, -1, -1, -1].

To handle this, we need to also track groups of connected nodes (I used union-find).
So, we check this additional condition: There is only one group of connected nodes.
*/

class Solution {
public:
    int find(vector<int>&ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    bool processLink(vector<int> &pars, vector<int>&ds, int parent, int child) {
        if (child == -1)
            return true;
        auto p = find(ds, parent), c = find(ds, child);
        if (p != c) {
            ds[p] += ds[c];
            ds[c] = p;
        }
        return ++pars[child] < 2;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& lCh, vector<int>& rCh) {
        vector<int> pars(n), ds(n, -1);
        for (int i = 0; i < n; ++i) {
            if (!processLink(pars, ds, i, lCh[i]) || !processLink(pars, ds, i, rCh[i]))
                return false;
        }
        return count_if(begin(pars), end(pars), [](int i) { return i == 0; }) == 1 &&
            count_if(begin(ds), end(ds), [](int i) { return i < 0; }) == 1;
    }
};
