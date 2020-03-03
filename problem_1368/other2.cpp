/*
Intuition:

If, for example, our current cell arrow is "->" but we want to move to the cell below, then we incur 1 cost. This means that, there is an edge with cost 1 between the 2 cells.
If we move to the adjacent cell along the direction of arrow, we do not incur cost.
So, our problem becomes: find the shortest path from the source (0,0) to the target (m-1,n-1), on the graph where edge weight is either 0 or 1.
This is a special graph, and we can use 0-1 BFS to solve. O(N). See this: https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/
If we use Dijkstra's algorithm, the complexity is not optimal: O(NlogN).
 */

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        deque<pair<int, int>> q{{0, 0}};  // for the pair, the first element is the cell position, the second is the path cost to this cell
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        unordered_set<int> visited;
        
        int res = 0;
        while(!q.empty())
        {
            auto t = q.front(); 
            q.pop_front();

            int curi = t.first / n, curj = t.first % n;
            if (visited.insert(t.first).second)  // If we have never visited this node, then we have the shortest path to this node
                res = t.second;
            
            if (curi == m-1 && curj == n-1)
                return res;
            
            for (auto dir: dirs)
            {
                int x = curi + dir[0];
                int y = curj + dir[1];
                int pos = x * n + y;
                if (x<0 || x>=m || y<0 || y>=n || visited.count(pos)) continue;
                
                int cost;
                if (grid[curi][curj] == 1 && dir[0] == 0 && dir[1] == 1) cost = 0;
                else if (grid[curi][curj] == 2 && dir[0] == 0 && dir[1] == -1) cost = 0;
                else if (grid[curi][curj] == 3 && dir[0] == 1 && dir[1] == 0) cost = 0;
                else if (grid[curi][curj] == 4 && dir[0] == -1 && dir[1] == 0) cost = 0;
                else cost = 1;
                
                if (cost == 1)
                    q.push_back({pos, t.second + cost});
                else
                    q.push_front({pos, t.second + cost});
            }
        }
        return res;
    }
};
