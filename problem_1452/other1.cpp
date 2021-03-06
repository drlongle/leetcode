class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favs) {
        unordered_map<string, int> ids;
        int id = 0;
        vector<vector<int>> comps(favs.size());
        for (auto i = 0; i < favs.size(); ++i) {
            for (auto &comp : favs[i]) {
                if (!ids.count(comp)) {
                    ids[comp] = id++;
                }
                comps[i].push_back(ids[comp]);
            }
        }
        for (auto &comp: comps)
            sort(begin(comp), end(comp));
        vector<int> res;
        for (auto i = 0; i < comps.size(); ++i) {
            bool notSubset = true;            
            for (auto j = 0; j < comps.size() && notSubset; ++j) {
                if (i == j)
                    continue;
                notSubset = !includes(begin(comps[j]), end(comps[j]), begin(comps[i]), end(comps[i]));
            }
            if (notSubset)
                res.push_back(i);
        }
        return res;
    }
};
