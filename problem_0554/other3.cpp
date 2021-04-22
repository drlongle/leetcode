class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> vmap;
        int maxi = 0;
        for (int i= 0; i < wall.size(); i++) {
            int s = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                s += wall[i][j];
                vmap[s]++;
                maxi = max(maxi, vmap[s]);
            }
        }

        return wall.size() - maxi;
    }
};
