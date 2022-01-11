/*
2 rows will be identical after flips, if they are the same previously or they are complementary.
We will store every row in map (to count their frequency).
The solution is the maximum (m[row[i]]+m[inverse(row[i]) ] ) where i go from 0 to n-1
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {        
        map<vector<int>,int>m;
        for(int i=0;i<matrix.size();i++)
            m[matrix[i]]++;

        int ans=0;        
        for(int i=0;i<matrix.size();i++){
            vector<int>inverse(matrix[i].size(),0);
            for(int j=0;j<matrix[i].size();j++)
                inverse[j] = (matrix[i][j]^1);
            
            ans=max(ans, m[matrix[i]]+ m[inverse]);
        }

        return ans;
    }
};
