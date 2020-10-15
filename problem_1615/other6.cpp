/*
We have two cases here:

There is one city i_max with the biggest number of roads.
We include this city in the maximum network rank. We can a pair by doing a linear scan of remaining cities.

There are many - cnt_max - cities with the same biggest number of roads (e.g. we have a fully connected graph).
We include two of such cities in the maximum network rank. We just need to find if there is a pair of such
cities that is not connected with a road.

The last bit is a bit tricky, so let's think about a fully connected graph with n nodes. Each node has the
same number of edges (n - 1), and there are n * (n - 1) / 2 edges total. If there is one edge missing,
that means there are two nodes that are not connected.

Therefore, we need to check if cities with the same biggest number of roads form a fully connected graph
(or subgraph). To do so, we need to go through our roads again, and count roads that connect two cities
with the biggest number of roads.
*/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n);
        size_t res = 0, first_max = 0, second_max = 0;
        unordered_set<int> adj;
        for (auto r : roads) {
            ++cnt[r[0]];
            ++cnt[r[1]];
            adj.insert((min(r[0], r[1]) << 16) + max(r[0], r[1]));
        }
        int i_max = max_element(begin(cnt), end(cnt)) - begin(cnt);
        int cnt_max = count(begin(cnt), end(cnt), cnt[i_max]);
        if (cnt_max == 1) {
            for (auto j = 0; j < n; ++j)
                if (i_max != j)
                    res = max(res, cnt[i_max] + cnt[j] - adj.count((min(i_max, j) << 16) + max(i_max, j)));
        }
        else {
            int roads_between_max = count_if(begin(roads), end(roads), [&] (vector<int>&r) {
                return cnt[r[0]] == cnt[i_max] && cnt[r[1]] == cnt[i_max];
            });
            res = 2 * cnt[i_max] - (cnt_max * (cnt_max - 1) / 2 > roads_between_max ? 0 : 1);
        }
        return res;
    }
};