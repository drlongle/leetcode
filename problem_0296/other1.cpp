class Solution {
public:
    int help (vector<int> & hor){
        sort (hor.begin(), hor.end());
        int left = 0, right = hor.size() - 1;
        int cnt = 0;
        while (left < right){
            cnt += hor[right--] - hor[left++];
        }
        return cnt;

    }
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> hor; vector<int> vert;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1) {vert.push_back (j);
                    hor.push_back(i);}
            }
        }

        return help (hor) + help (vert);
    }
};
