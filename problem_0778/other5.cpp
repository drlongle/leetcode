class Solution {
public:
    // Fill every possible cell which can be visited
    void fillPath(vector<vector<int>> & grid, vector<vector<bool>> & visited, int row, int col, int t)
    {
        // Check for being in-boundary
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid.size())
            return;
        // Check if the cell can be swimmed through or was visited
        if(grid[row][col] > t || visited[row][col])
            return;
        // Visit the cell and try every neighbour (down, up, left, right)
        visited[row][col] = true;
        fillPath(grid, visited, row + 1, col, t);
        fillPath(grid, visited, row - 1, col, t);
        fillPath(grid, visited, row, col - 1, t);
        fillPath(grid, visited, row, col + 1, t);
    }

    int swimInWater(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int left = 0;
        int right = n * n - 1;
        int mid, bestT;
        // Binary search for a minimum T value such that it is possible to arrive at (N-1, N-1)
        // Left is the lower limit and right is the higher limit of T
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            vector<vector<bool>> visited (n, vector<bool>(n));

            fillPath(grid, visited, 0, 0, mid);

            // If (N-1, N-1) is reachable, bestT is updated and we can try to lower the right limit.
            // Else, we increase the left limit and try again
            if(visited[n - 1][n - 1])
            {
                bestT = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return bestT;
    }
};
