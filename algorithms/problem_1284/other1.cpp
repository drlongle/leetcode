
class Solution {
public:
    
    int xlen, ylen;
    
    bool isvalidCell(int x,int y) {
        return (x<0 || y<0 || x>=xlen || y>=ylen) ? false : true;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        if(mat.empty())
            return 0;
        xlen = mat.size();
        ylen = mat[0].size();
        int max = (1<< (xlen*ylen )) -1;
        int ans  = INT_MAX;
        for (int i = 0; i <= max; i++) {
            int tempans=0;
            vector<vector<int>> tempmat = mat;
            
            for (int j = 0;j < xlen;j++) {
                for (int k = 0; k < ylen; k++) {
                    int bitindex = j*ylen + k;
                    if (i & (1<<bitindex)) {
                        tempans++;
                        tempmat[j][k] = !tempmat[j][k];
                        if (isvalidCell(j-1,k)) tempmat[j-1][k] = !tempmat[j-1][k];
                        if (isvalidCell(j+1,k)) tempmat[j+1][k] = !tempmat[j+1][k];
                        if (isvalidCell(j,k-1)) tempmat[j][k-1] = !tempmat[j][k-1];
                        if (isvalidCell(j,k+1)) tempmat[j][k+1] = !tempmat[j][k+1];
                    }
                }
            }
            
            bool isvalid = true;
            for (int j = 0; j < xlen; j++) {
                for (int k = 0; k < ylen; k++) {
                    if(tempmat[j][k]) isvalid = false;
                }
            }
            
            if (isvalid) {
                ans = min(ans,tempans);
            }
        }
        
        if (ans == INT_MAX) return -1;
        else return ans;
    }
};
