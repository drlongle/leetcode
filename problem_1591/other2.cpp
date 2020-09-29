class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        //identify the possible four corners of the rectangle for each color
        vector<vector<int>> grid(61, vector<int>(4, -1));
        int n = targetGrid.size(), m = targetGrid[0].size();
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                int color = targetGrid[row][col];
                (grid[color][0] == -1) ? grid[color][0] = row : grid[color][0] = min(row, grid[color][0]);
                (grid[color][1] == -1) ? grid[color][1] = col : grid[color][1] = min(col, grid[color][1]);
                (grid[color][2] == -1) ? grid[color][2] = row : grid[color][2] = max(row, grid[color][2]);
                (grid[color][3] == -1) ? grid[color][3] = col : grid[color][3] = max(col, grid[color][3]);
            }
        }

        //build graph
        vector<vector<int>> graph(61, vector<int>(61, 0));
        vector<int> indegree(61, -1);
        for(int color=1; color<61; color++){
            if(grid[color][0] == -1) continue;
            indegree[color] = 0;
            vector<int> visited(61, 0);
            for(int row=grid[color][0]; row<=grid[color][2]; row++){
                for(int col=grid[color][1]; col<=grid[color][3]; col++){
                    if(targetGrid[row][col] != color && !visited[targetGrid[row][col]]){
                        visited[targetGrid[row][col]] = 1;
                        graph[targetGrid[row][col]][color] = 1;
                        indegree[color]++;
                    }
                }
            }
        }

        //topological sort
        queue<int> q;
        for(int color=1; color<=60; color++) if(indegree[color] == 0) q.push(color);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int color=1; color<61; color++){
                if(graph[front][color] == 1){
                    indegree[color]--;
                    if(indegree[color] == 0) q.push(color);
                }
            }
        }

        for(int color=1; color<61; color++){
            if(indegree[color] > 0) return false;
        }
        return true;

    }
};
