/*
Explanation
Just use BFS to walk on the grid. Please note that, only when the neighbouring cell has a street connected to this cell, you can walk to the neighbouring cell. Also, please note the entry point of the last cell.

In the code, Pair.from means the direction of the last cell of the current cell.
 */
class Solution {
    struct Pair {
        int x, y;
        char from;
        
        Pair(int x, int y, int from) {
            this->x = x;
            this->y = y;
            this->from = from;
        }
    };
    
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<Pair> q;
        bool visited[305][305][26];
        memset(visited, 0, sizeof(visited));
        vector<char> direction = {'u', 'd', 'l', 'r'};
        for (auto c: direction) {
            q.emplace(0, 0, c);
            visited[0][0][c - 'a'] = true;
        }
        
        while (!q.empty()) {
            Pair p = q.front();
            q.pop();
            int x = p.x, y = p.y;
            char from = p.from;
            
            // next is up
            if (grid[x][y] == 2 && from == 'd' || grid[x][y] == 5 && from == 'l' || 
                grid[x][y] == 6 && from == 'r')
                if (x > 0 && (grid[x-1][y] == 2 || grid[x-1][y] == 3 || grid[x-1][y] == 4) && !visited[x-1][y]['d' - 'a']) {
                    q.emplace(x - 1, y, 'd');
                    visited[x-1][y]['d' - 'a'] = true;
                }
            // next is left
            if (grid[x][y] == 1 && from == 'r' || grid[x][y] == 3 && from == 'd' ||
                grid[x][y] == 5 && from == 'u')
                if (y > 0 && (grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6) && !visited[x][y-1]['r' - 'a']) {
                    q.emplace(x, y - 1, 'r');
                    visited[x][y-1]['r' - 'a'] = true;
                }
            // next is down
            if (grid[x][y] == 2 && from == 'u' || grid[x][y] == 3 && from == 'l' ||
                grid[x][y] == 4 && from == 'r')
                if (x < n - 1 && (grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6) && !visited[x+1][y]['u' - 'a']) {
                    q.emplace(x + 1, y, 'u');
                    visited[x+1][y]['u' - 'a'] = true;
                }
            // next is right
            if (grid[x][y] == 1 && from == 'l' || grid[x][y] == 4 && from == 'd' ||
                grid[x][y] == 6 && from == 'u')
                if (y < m - 1 && (grid[x][y+1] == 1 || grid[x][y+1] == 3 || grid[x][y+1] == 5) && !visited[x][y+1]['l' - 'a']) {
                    q.emplace(x, y + 1, 'l');
                    visited[x][y+1]['l' - 'a'] = true;
                }
        }
        
        for (auto c: direction)
            if (visited[n-1][m-1][c - 'a'])
                return true;
        return false;
    }
};
