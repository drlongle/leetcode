class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>> &pref, vector<vector<int>> &pairs)
    {
        vector<unordered_map<int, int>> mp(n);
        vector<int> distance(n);
        for (int i = 0; i < n; ++i)
        {
            int prefsize = pref[i].size();
            for (int j = 0; j < prefsize; ++j)
                mp[i][pref[i][j]] = j;
        }

        for (auto &p : pairs)
        {
            distance[p[0]] = mp[p[0]][p[1]];
            distance[p[1]] = mp[p[1]][p[0]];
        }
        int unhappy = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < distance[i]; ++j)
            {
                int x = pref[i][j];
                for (int k = 0; k < distance[x]; ++k)
                {
                    if (i == pref[x][k])
                    {
                        unhappy++;
                        j = k = n;
                    }
                }
            }
        }
        return unhappy;
    }
};