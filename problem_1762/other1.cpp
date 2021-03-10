class Solution {
public:
    vector<int> findBuildings(vector<int>& hs) {
        vector<int> res;
        for (int i = hs.size() - 1; i >= 0; --i)
            if (res.empty() || hs[i] > hs[res.back()])
                res.push_back(i);
        return vector<int>(rbegin(res), rend(res));
    }
};
