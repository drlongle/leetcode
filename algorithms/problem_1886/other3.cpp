class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        for(int i=0; i<4; i++)
        {
            if(mat==target)
                return true;

            rotateRight(target);
        }

        return false;
    }

    void rotateRight(vector<vector<int>> &target)
    {
        int len=target.size();

        for(int i=0; i<len; i++)
            for(int j=0; j<i; j++)
                swap(target[i][j], target[j][i]);

        for(int i=0; i<len; i++)
            for(int j=0; j<len/2; j++)
                swap(target[i][j], target[i][len-1-j]);
    }
};
