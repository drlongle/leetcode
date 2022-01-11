struct Hash {
    size_t operator()(const pair<int,int>&x)const{
        return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
    }
};

class Solution {
public:
    // solution 1 - 416ms, 16MB
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<pair<int,int>, Hash> seen;
        int res = numeric_limits<int>::max();
        for (const auto& p : points) {
            int x1 = p[0], y1 = p[1];
            for (auto[x2,y2] : seen) 
                if (seen.count({x1, y2}) && seen.count({x2, y1})) {
                    int area = abs(x1 - x2)*abs(y1 - y2);
                    res = min(area, res);
                }
            
            seen.emplace(x1, y1);
        }
        return res == numeric_limits<int>::max() ? 0 : res;
    }
};
