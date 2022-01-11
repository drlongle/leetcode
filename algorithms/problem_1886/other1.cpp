class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int rows = mat.size();
        int col = mat[0].size();
        if(mat==target)
            return true;
        for(int i=0; i<4; i++) {
            reverse(mat.begin(), mat.end()) ;
            for(int j=0; j<rows; j++) {
                for(int k=j+1; k<col; k++) {
                    swap(mat[j][k], mat[k][j]);
                }
            }
            if(mat==target)
                return true;
        }
        return false;
    }
};
