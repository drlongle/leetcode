class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        std::vector<std::string> res;
        int lo{lower}, hi{upper};
        for(const auto &n: nums) {
            if(n < lo) continue;
            if(n > upper) break;
            
            if(n-1 > lo) res.emplace_back(std::to_string(lo)+"->"+std::to_string(n-1));
            else if(n-1 == lo) res.emplace_back(std::to_string(lo));
            lo = n+1;
        }
        
        if(lo < hi) res.emplace_back(std::to_string(lo)+"->"+std::to_string(hi));
        else if(lo == hi) res.emplace_back(std::to_string(lo));
        return res;
    }
};

