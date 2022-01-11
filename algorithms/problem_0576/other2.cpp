class Solution {
public:
    int findPaths(int m, int n, int N, int sr, int sc) {
        vector<vector<long long>> mydp(m,vector<long long>(n,0));
        vector<vector<long long>> temp(m,vector<long long>(n,0));
        int mod = (int)(1e9+7);

        for (int k=1;k<=N;k++)
        {
            for (int i=0;i<m;i++)
            {
                for (int j=0;j<n;j++)
                {
                    temp[i][j]=(i==0)+(j==0)+(i==m-1)+(j==n-1); // to update no. of ways to get out if N==1
                    // rest of the code adds ways of getting out by taking one step to some adjacent cell
                    if (i>0)
                        temp[i][j]+=mydp[i-1][j];
                    if (i<m-1)
                        temp[i][j]+=mydp[i+1][j];
                    if (j>0)
                        temp[i][j]+=mydp[i][j-1];
                    if (j<n-1)
                        temp[i][j]+=mydp[i][j+1];

                    temp[i][j]=temp[i][j]%mod;
                }
            }
            mydp=temp; // update the dp array
        }
        return mydp[sr][sc];
    }
};
