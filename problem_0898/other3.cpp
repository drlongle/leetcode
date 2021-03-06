class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, prev;
        for (auto cur : A) {
            unordered_set<int> temp = {cur};
            for (auto i : prev) {
                temp.insert(i | cur);
            }
            for (auto i : temp) {
                res.insert(i);
            }
            prev = temp;
        }
        return res.size();
    }
};
