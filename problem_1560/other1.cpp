class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& r) {
        vector<int> res;
        for (int i = 1; i <= n; ++i)
            if ((r.front() <= r.back() && i >= r.front() && i <= r.back()) ||
                (r.front() > r.back() && (i >= r.front() || i <= r.back())))
                res.push_back(i);
        return res;
    }
};