class Solution {
public:
    unordered_set<string> s;
    string search(vector<vector<int>>& grid, int x, int y, int& k){
        if(x < 0 || y < 0 || x >= grid.size() || y>=grid[0].size())return "";
        string s = "";
        if(grid[x][y]){
            s = to_string(k);
            k++;
            grid[x][y] = 0;
            s += search(grid, x+1, y, k) + ',';
            s += search(grid, x-1, y, k) + ',';
            s += search(grid, x, y+1, k) + ',';
            s += search(grid, x, y-1, k) + ',';
        }
        return s;
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]){
                    int tmp = 0;
                    string str = search(grid, i, j, tmp);
                    cout<<str<<endl;
                    s.insert(str);
                }
            }
        }
        return s.size();
    }
};
