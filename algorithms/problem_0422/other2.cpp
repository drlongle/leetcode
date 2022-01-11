class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        
        int row = words.size();
        int col = words[0].length();
        
        if( row != col)
            return false;
      
        for(int i = 0;i<row;i++)
        {
            int j = 0;
            for(int k = 0;j< row and k < words[i].length() ;j++ , k++)
            {
                if( words[i][j] != words[j][i])
                    return false;
            }
            
            if( j != words[i].length())
                return false;
        }
        
        return true;
        
    }
};

