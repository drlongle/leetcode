class Solution { // DP: DFS+memoization
public: //Coding cost: 35Lines;  Time/Space: O(M*N*K*(M+N));O(M*N*K) 
    int ways(vector<string>& pizza, int k) {
        //Step 4: third assistant: prefix sum matrix
        const int m = pizza.size(), n = pizza[0].size(), kMod = 1e9+7;
        vector<vector<int> > A(m+1, vector<int>(n+1));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                A[i+1][j+1]=A[i+1][j] + A[i][j+1] - A[i][j] + (pizza[i][j] == 'A');
        
        //step 3: second assistant: assistent of assistant
        auto hasApple = [&](int r1, int c1, int r2, int c2){
            return A[r2+1][c2+1] - A[r2+1][c1] - A[r1][c2+1] + A[r1][c1] > 0;
        };
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        
        //step 2: first assistant
        // dp(m, n, k) := # of ways to cut pizza[m:M][n:N] with k cuts.
        function<int(int,int,int)> dfs = [&](int i, int j, int k)->int{
            if(k == 0) return hasApple(i, j, m-1, n-1);
            int& ans = dp[i][j][k];
            if(ans != -1) return ans;
            ans = 0;
            // current cut is between idx and idx+1 row ( collum);
            for(int idx = i; idx < m - 1; idx++) // Cut horizontally.
                ans = (ans + hasApple(i, j, idx, n - 1) * dfs(idx+1, j, k - 1)) % kMod;
            for(int idx = j; idx < n - 1; idx++) // Cut vertically.
                ans = (ans + hasApple(i, j, m -1, idx) * dfs(i, idx+1, k - 1)) % kMod;
            return ans;
        };        
        //Step 1: begin with the goal
        return dfs(0, 0, k-1);
    }
};
