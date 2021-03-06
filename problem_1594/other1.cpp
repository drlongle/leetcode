class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {

        int r =  grid.size();
        int c = grid[0].size();

        // 3D dp vector contains max and min product value for each grid position
        vector<vector<vector<long long int>>>dp(r,vector<vector<long long int>>(c,vector<long long int>(2,0)));

        // store bottom right value
        dp[r-1][c-1][0] = grid[r-1][c-1];
        dp[r-1][c-1][1] = grid[r-1][c-1];

        // store multiplication min and max value in c-1 th column
        for(int i=r-1;i>0;i--)
        {
            dp[i-1][c-1][0] = dp[i][c-1][0] * grid[i-1][c-1];
            dp[i-1][c-1][1] = dp[i][c-1][1] * grid[i-1][c-1];
        }

        // store multiplication min and max value in r-1 th row
        for(int i=c-1;i>0;i--)
        {
            dp[r-1][i-1][0] = dp[r-1][i][0] * grid[r-1][i-1];
            dp[r-1][i-1][1] = dp[r-1][i][1] * grid[r-1][i-1];
        }

        long long int w,x,y,z;

        // start from r-2, c-2 position and loop till 0,0 and calculate max and min product for each position
        for(int i=r-2;i>=0;i--)
        {
            for(int j=c-2;j>=0;j--)
            {
                w = grid[i][j]*dp[i+1][j][0];
                x = grid[i][j]*dp[i][j+1][0];
                y = grid[i][j]*dp[i+1][j][1];
                z = grid[i][j]*dp[i][j+1][1];

                // 0th index stores max product
                dp[i][j][0] = max({w,x,y,z});

                //1th index stores min product
                dp[i][j][1] = min({w,x,y,z});
            }
        }

        // IF max dp[0][0][0] is negative then return -1 otherwise return dp[0][0][0]%MOD_VALUE
        return dp[0][0][0]<0?-1:(dp[0][0][0])%1000000007;

    }
};
