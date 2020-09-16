/*
Answer can never be greater than 2 because it takes only two diagonal blocks to detach corner block from rest of
the island. Just make each block with value one to zero and search in rest of the matrix, when for a particular block
you can get island disconnected it is 1 else 2.
*/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int rows, int cols, int i, int j, vector<vector<int>>& visited){
        visited[i][j] = 1;
        if(i<rows-1 && visited[i+1][j]==0 && grid[i+1][j]==1 )dfs(grid, rows, cols, i+1, j, visited);
        if(i>0 && visited[i-1][j]==0 && grid[i-1][j]==1 )dfs(grid, rows, cols, i-1, j, visited);
        if(j<cols-1 && visited[i][j+1]==0 && grid[i][j+1]==1 )dfs(grid, rows, cols, i, j+1, visited);
        if(j>0 && visited[i][j-1]==0 && grid[i][j-1]==1 )dfs(grid, rows, cols, i, j-1, visited);
        return;
    }

    int countIslands(vector<vector<int>>& grid, int rows, int cols){
        vector<vector<int>> visited(rows, vector<int>(cols,0));
        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    dfs(grid, rows, cols, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }

    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(countIslands(grid,rows,cols)!=1){
            return 0;
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(countIslands(grid,rows,cols)!=1){
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
