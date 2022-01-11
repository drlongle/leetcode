class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(!grid.size()) return 0;
        vector<vector<int>> bombs(grid.size(),vector<int>(grid[0].size()));
        int max_enemies=0;
        int n_rows=grid.size();
        int n_cols=grid[0].size();
        for(int i=0;i<n_rows;i++){
            int left_count=0,right_count=0;
            int left_pointer=0,right_pointer=n_cols-1;
            while(left_pointer<n_cols && right_pointer>=0){
                if(grid[i][left_pointer]=='E') ++left_count;
                else if(grid[i][left_pointer]=='W') left_count=0;
                else bombs[i][left_pointer]+=left_count;
                if(grid[i][right_pointer]=='E') ++right_count;
                else if(grid[i][right_pointer]=='W') right_count=0;
                else bombs[i][right_pointer]+=right_count;
                ++left_pointer;
                --right_pointer;
            }
        }
        for(int i=0;i<n_cols;i++){
            int up_count=0,down_count=0;
            int up_pointer=0,down_pointer=n_rows-1;
            while(up_pointer<n_rows && down_pointer>=0){
                if(grid[up_pointer][i]=='E') ++up_count;
                else if(grid[up_pointer][i]=='W') up_count=0;
                else {
                    bombs[up_pointer][i]+=up_count;
                    max_enemies=max(max_enemies,bombs[up_pointer][i]);
                }
                if(grid[down_pointer][i]=='E') ++down_count;
                else if(grid[down_pointer][i]=='W') down_count=0;
                else {
                    bombs[down_pointer][i]+=down_count;
                    max_enemies=max(max_enemies,bombs[down_pointer][i]);
                }
                ++up_pointer;
                --down_pointer;
            }
        }

        return max_enemies;
    }
};
