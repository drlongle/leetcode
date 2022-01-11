class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        
        //Iterate through all words.
        for(int i = 0; i < words.size(); i++)
        {
            int j = 0;
            
            //Check in other words the ith char should be same as the jth char in curr word.
            for(int k = 0; j < words[i].size() && k < words.size(); j++, k++)
            {
                if(words[i][j] != words[k][i])
                    return false;                
            }
            
            //Check if we reach till the end of ith word.
            if(j != words[i].size())
                return false;
        }
        
        return true;
    }
};

