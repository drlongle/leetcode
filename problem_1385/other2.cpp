class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
        return count_if(begin(A), end(A), [&](const auto &a) {
            return all_of(begin(B), end(B), [&](const auto &b) {
                return abs(a - b) > d;
            });
        });
    }
};
