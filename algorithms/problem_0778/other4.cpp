class Solution {
public:

    bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();

    // Check the boundary of the grid and make sure that this cell didn't visit before

    static bool is_valid(int r, int c, int n, vector < vector < int > >& vis){
        return (r >= 0 && r < n && c >= 0 && c < n && !vis[r][c]);
    }

    static bool DFS(vector < vector < int > >& grid, vector < vector < int > >& vis, int r, int c, int n, int T){
        if(grid[r][c] > T) return false;
        if(r == n - 1 && c == n - 1) return true;
        vis[r][c] = true;
        //  Make a vector with the 4 adjacent directory
        vector < pair < int, int > > dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // Check all the adjacent cells of the current cell if one reach the goal will return true
        for(auto& [x, y] : dir){
            if(is_valid(r + x, c + y, n, vis))
                if(DFS(grid, vis, r + x, c + y, n, T)) return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        // Make a binary search for the smallest T that achieve our goal
        // the boundary of the binary search is the Min and the Max element in the grid
        int n = grid.size();
        int l = 0, r = n * n, best = -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            vector < vector < int > > vis(n + 1, vector < int > (n + 1));
            (DFS(grid, vis, 0, 0, n, m) ? r = m - 1, best = m : l = m + 1);
        }
        return best;
    }
};
