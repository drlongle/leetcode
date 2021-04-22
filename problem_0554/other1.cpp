class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> um;
        int max_val = 0;
        int m = wall.size();

        for(int i=0;i<m;i++){
            int curr=0;
            for(int j=0;j<wall[i].size()-1;j++){
                curr+=wall[i][j];
                max_val=max(++um[curr],max_val);
            }
        }

        return m-max_val;
    }
};