class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int n = scores.size();
        vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](const int &x, const int &y) {
            return make_pair(ages[x], scores[x]) < make_pair(ages[y], scores[y]);
        });
        map<int, int> dp = {{0, 0}}; // mapping from player's score to team's score
        for (int i = 0; i < n; ++i) {
            auto t = dp.upper_bound(scores[ind[i]]);
            const int may = (--t)->second + scores[ind[i]];
            t = dp.lower_bound(scores[ind[i]]);
            // Every team's score below "may" are suboptimal and can be deleted.
            for (; t != dp.end() && t->second <= may; dp.erase(t++))
                ;
            dp[scores[ind[i]]] = may;
        }
        return dp.rbegin()->second;

    }
};
