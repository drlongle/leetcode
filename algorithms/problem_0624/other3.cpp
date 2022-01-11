class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int mini = INT_MAX, maxi = INT_MIN;
        int res = -1, min_idx, max_idx;

        for (int i = 0; i < arrays.size(); i++) {
            int newMin = min(mini, arrays[i][0]);
            if (mini != newMin) {
                mini = newMin;
                min_idx = i;
            }
        }
        for (int i = 0; i < arrays.size(); i++) {
            int newMax = max(maxi, arrays[i].back());
            if (i!=min_idx && maxi != newMax) {
                maxi = newMax;
                max_idx = i;
            }
        }

        res = abs(maxi - mini);
        mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < arrays.size(); i++) {
            int newMax = max(maxi, arrays[i].back());
            if (maxi != newMax) {
                maxi = newMax;
                max_idx = i;
            }
        }
        for (int i = 0; i < arrays.size(); i++) {
            int newMin = min(mini, arrays[i][0]);
            if (i!=max_idx && mini != newMin) {
                mini = newMin;
                min_idx = i;
            }
        }

        res = max(res, abs(maxi - mini));

        return res;
    }
};
