static int MOD=1e9+7;
class Solution {
public:
    vector<vector<vector<int>>> memo;
    bool leftBoundaryContains(vector<string>& pizza,int col,int top)		//Check if left piece contains an apple
    {
        for(int i=top;i<pizza.size();i++)
            if(pizza[i][col]=='A')
                return true;
        return false;
    }
    bool topBoundaryContains(vector<string>& pizza,int left,int row)	//Check if top piece contains an apple
    {
        for(int i=left;i<pizza[0].size();i++)
            if(pizza[row][i]=='A')
                return true;
        return false;
    }
    int dp(vector<string>& pizza,int left,int top,int k)
    {
        if(memo[top][left][k]!=-1)
            return memo[top][left][k];
        if(k==1)		//Return 1 if the last piece left contains apple else 0.
        {
            for(int i=top;i<pizza.size();i++)
                for(int j=left;j<pizza[0].size();j++)
                    if(pizza[i][j]=='A')
                        return 1;
            return 0;
        }
        memo[top][left][k]=0;
        bool leftContains=false,topContains=false;	//These flags make the solution smater by skipping rechecking larger pieces whose smaller ones have appples.
        for(int c=left;c<pizza[0].size()-1;c++)		 //Move the left boundary till the last column (excluding the last column)
            if(leftContains||leftBoundaryContains(pizza,c,top))
            {
                leftContains=true;			//Mark that left piece will always contain apple from now on.
                memo[top][left][k]=(memo[top][left][k]+dp(pizza,c+1,top,k-1))%MOD;
                
            }
        for(int r=top;r<pizza.size()-1;r++)			 //Move the top boundary till the last row (excluding the last row)
            if(topContains||topBoundaryContains(pizza,left,r))
            {
                topContains=true;			//Mark that top piece will always contain apple from now on.
                memo[top][left][k]=(memo[top][left][k]+dp(pizza,left,r+1,k-1))%MOD;
                
            }
        return memo[top][left][k];
    }
    int ways(vector<string>& pizza, int k) 
    {
        memo.resize(pizza.size(),vector<vector<int>>(pizza[0].size(),vector<int>(k+1,-1)));
        return dp(pizza,0,0,k);
    }
};
