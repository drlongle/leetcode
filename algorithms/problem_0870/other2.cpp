class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        const int n = size(A);
        multiset<int> sa(cbegin(A), cend(A));
        vector<int> res;
        for (auto val : B) {
            auto it = sa.upper_bound(val);
            if (it != cend(sa)) {
                res.push_back(*it);
                sa.erase(it);
            }
            else {
                res.push_back(*sa.begin());
                sa.erase(sa.begin());
            }
        }

        return res;
    }
};