class Solution
{
public:

    std::vector<int> shortestToChar(std::string S, char C) 
    {
        std::vector<int> res;
        std::vector<int> loc;

        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == C)
            {
                loc.push_back(i);
            }
        }

        if(loc.size() == 1)
        {
            for(int i = 0; i < S.size(); i++)
            {
                res.push_back(std::abs(i - loc[0]));
            }
        
            return res;
        }
    
        int k = 0;
    
        for(int i = 0; i < S.size(); i++)
        {
            const auto d1 = std::abs(i - loc[k]);
            const auto d2 = std::abs(i - loc[k+1]);
        
            if(d1 <= d2)
            {
                res.push_back(d1);
            }
            else if(d1 > d2)
            {
                res.push_back(d2);
            }
        
            if(d2 == 0 && k+1 < loc.size()-1) 
            {
                k++;
            }
        }

        return res;
    }
};
