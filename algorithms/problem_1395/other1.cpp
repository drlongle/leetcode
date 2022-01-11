/*
For each solder, count how many solders on the left and right have less and greater ratings.

This solder can form less[left] * greater[right] + greater[left] * less[right] teams
*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (auto i = 1; i < rating.size() - 1; ++i) {
            int less[2] = {}, greater[2] = {};
            for (auto j = 0; j < rating.size(); ++j) {
                if (rating[i] < rating[j])
                    ++less[j > i];
                if (rating[i] > rating[j])
                    ++greater[j > i];
            }
            res += less[0] * greater[1] + greater[0] * less[1];
        }
        return res;
    }
};
