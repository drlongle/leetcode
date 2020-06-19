#define MAX 100
#define INF 1000000
class Solution {
public:
    int costs[MAX][MAX] = {};
    int memo[MAX][MAX] = {};
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int t = i; t <= j; t++)
                    costs[i][j] += abs(houses[(i + j) / 2] - houses[t]);
        return dp(houses, n, k, 0);
    }
    int dp(vector<int>& houses, int n, int k, int i) {
        if (k == 0 && i == n) return 0;
        if (k == 0 || i == n) return INF;
        if (memo[k][i] != 0) return memo[k][i];
		int ans = INF;
        for (int j = i; j < n; j++)
            ans = min(ans, costs[i][j] + dp(houses, n, k-1, j + 1));
        return memo[k][i] = ans;
    }
};