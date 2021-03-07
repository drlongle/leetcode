class Solution {
public:
    int maximumScore(vector<int>& ns, vector<int>& ms) {
        int n = ns.size(),m = ms.size();
        int f[m + 10][m + 10];
        memset(f, 0xc0, sizeof f);
        // State Representation - f[i][j]:
        // ith manipulation, where first j elements have been removed
        f[0][0] = 0;

        for(int i = 1; i <= m; i++)
        {
            f[i][0] = f[i-1][0] + ms[i-1] * ns[n-i];
            for(int j = 1; j <= i; j++)
            {
                int addFront = f[i-1][j-1] + ms[i-1] * ns[j - 1];
                int addBack = f[i-1][j] > -1e9 ? f[i-1][j] + ms[i-1] * ns[n-(i-j)] : -1e9;
                f[i][j] = max(addFront, addBack);
            }
        }
        int ans = -1e9;
        for(int i = 0; i <= m; i++)
            ans = max(f[m][i],ans);
        return ans;
    }
};
