//                  TIME: O(m * n * n), space: O(m * n)

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans = 0, m = mat.size(), n = mat[0].size(), temp;
        
        int up[151][151], left[151][151];
        // up[i][j] = #consecutive ones in the upward direction starting from (i,j)
        // left[i][j] = #consecutive ones in the leftward direction starting from (i,j)
        
        left[0][0] = up[0][0] = ans = mat[0][0];
        for(int i=1; i<n; i++) {                        // for 1st row
            if(!mat[0][i]) up[0][i] = left[0][i] = 0;
            else {
                up[0][i] = 1;
                left[0][i] = 1 + left[0][i-1];
                ans += left[0][i];
            }
        }

        for(int i=1; i<m; i++) {                        // for 1st column
            if(!mat[i][0]) left[i][0] = up[i][0] = 0;
            else {
                left[i][0] = 1;
                up[i][0] = 1 + up[i-1][0];
                ans += up[i][0];
            }
        }
                
        for(int i=1; i<m; i++) for(int j=1; j<n; j++) {
            if(!mat[i][j]) up[i][j] = left[i][j] = 0;
            else {
                // evaluating the values of left[] and up[] for (i, j)
                up[i][j] = 1 + up[i-1][j];
                left[i][j-1] = 1 + left[i][j-1];            
                
                int maxH = 1 + up[i-1][j];
                temp = 0;
                int k = j;
                             
                while(maxH && k >= 0) {
                    if(up[i][k] == 0) break;
                    
                    maxH = min(maxH, up[i][k--]);
                    
                    temp += maxH;
                }
                ans += temp; // temp stores #subMatrices having bottom right corner at (i,j)
            }            
        }
        
        return ans;
    }
};
