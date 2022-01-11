/*
For each person, calculate the "friend distance" - how far the person he or she is paired with in the friend list.

Then, you can go through each person, and all friends that are closer (compared to the "friend distance").
*/

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        vector<unordered_map<int, int>> m(n);
        vector<int> dist(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < pref[i].size(); ++j)
                m[i][pref[i][j]] = j;
        }
        for (auto &p : pairs) {
            dist[p[0]] = m[p[0]][p[1]];
            dist[p[1]] = m[p[1]][p[0]];
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int d = 0; d < dist[i]; ++d) {
                int j = pref[i][d];
                for (int d1 = 0; d1 < dist[j]; ++d1) {
                    if (i == pref[j][d1]) {
                        ++res;
                        d = d1 = n;
                    }
                }
            }
        }
        return res;
    }
};