/*
We can improve our runtime if we sort points by x coordinate. That way, we only process points in
[qx - r, qx + r] interval. We use binary search to find the start of that interval.

Note that we need to fiddle with data structures here to make it fast. Sorting vector of vectors,
or using multiset adds noticeable overhead.
*/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& ps, vector<vector<int>>& queries) {
        vector<int> res;
        vector<array<int, 2>> sp;
        for (auto &p : ps)
            sp.push_back({p[0], p[1]});
        sort(begin(sp), end(sp));
        for (auto &q : queries) {
            int cnt = 0, rr = q[2] * q[2];
            auto it = lower_bound(begin(sp), end(sp), array<int, 2>{q[0] - q[2], 0});
            for (; it != end(sp) && (*it)[0] <= q[0] + q[2]; ++it)
                cnt += (q[0] - (*it)[0]) * (q[0] - (*it)[0]) + (q[1] - (*it)[1]) * (q[1] - (*it)[1]) <= rr;
            res.push_back(cnt);
        }
        return res;
    }
};
