class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        unordered_map<int, int> rowmap; // map of row idx to count
        unordered_map<int, int> colmap;

        vector<pair<int, int>> blacks;
        for(int i=0; i<picture.size(); i++){
            const auto& row = picture[i];
            for(int j=0; j<row.size(); j++){
                if(picture[i][j] == 'B'){
                    rowmap[i]++;
                    colmap[j]++;
                    blacks.push_back(make_pair(i,j));
                }
            }
        }

        int count = 0;
        for(const auto& black : blacks){
            int row = black.first;
            int col = black.second;
            if(rowmap[row] == 1 && colmap[col] == 1)
                count ++;
        }

        return count;
    }
};
