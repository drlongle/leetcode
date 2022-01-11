/*
dp[m][n]: is the number of left ones starting from (m,n)
- we first pre-calculate dp[m][n]
- we then spend O(n)*O(m^2) of time to find the maximum number of rectangles
  we can make with the bottom-right corner being mat[i][j]
- each row of an rectangle should be the same length (so the minimum number of the left ones on a straight
  line is the number of rectangle that can be made with that line height)
*/
class Solution 
{
    public:
    int numSubmat(vector<vector<int>>& mat) 
    {
        int result=0;
        int m=mat.size(),n=mat[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++) //calculate dp[m][n]
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    dp[i][j]=mat[i][j]; 
                }
                else
                {
                    if(mat[i][j]==0)
                    {
                        dp[i][j]=0;//no consecutive left zeroes starting from mat[i][j]
                    }
                    else
                    {
                        dp[i][j]=dp[i][j-1]+1;//count consecutive left zeroes
                    }
                }
            }
        }
        for(int j=0;j<n;j++) //from left to right
        {
            for(int i=0;i<m;i++) //from top to bottom
            {
                int minimum=dp[i][j];
                for(int k=i;k>-1;k--) //from i to top (count the number of rectangles that can be made)
                {
                    minimum=min(minimum,dp[k][j]); //the number of rectangles that can be made with the right edge extended from mat[i][j] to mat[k][j]
                    if(minimum==0)
                    {
                        break;
                    }
                    result+=minimum;
                }
            }
        }
        return result;
    }
};
