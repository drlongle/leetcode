class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target)
            return true;
        for(int i =0 ; i<3 ;i++) {
            int n=mat.size();
            //transpose mat
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    swap(mat[i][j], mat[j][i]);
                }
            }
            //reverse each row
            for(int i=0;i<n;i++){
                reverse(mat[i].begin(),mat[i].end());
            }

            if(mat == target)
                return true;
        }
        return false;
    }
};
