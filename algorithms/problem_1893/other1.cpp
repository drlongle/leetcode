class Solution {
public:
    const int MAX = 50;

    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> sums = vector<int>(MAX + 2, 0);
        for (int i = 0; i < ranges.size(); i++) {
            sums[ranges[i][0]] += 1;
            sums[ranges[i][1]+1] += -1;
        }
        bool ret = true;
        for (int i = 1; i <= MAX; i++) {
            sums[i] += sums[i-1];
            if (left <= i && i <= right && sums[i] == 0) {
                ret = false;
                break;
            }
        }

        return ret;
    }
};
