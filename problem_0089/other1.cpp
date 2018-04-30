class Solution {
public:
    
    
    vector<int> grayCode(int n) {        
        
        vector<int> res;
        if(n==0)
        {
            res.emplace_back(0);
            return res;
        }
        
        res = grayCode(n-1);
        auto a = 1<<(n-1);
        vector<int> resNew(res);
        for(auto i = res.rbegin() ; i!= res.rend(); ++i)
        {
            auto  x = (*i|a ); 
            resNew.emplace_back(x);
        }
        
        return resNew;
        
    }
};

