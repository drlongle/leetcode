class Solution {
    vector<int> one = {0,1,8};
    vector<vector<int>> two = {{0,0}, {1,1}, {6,9}, {8,8}, {9,6}};
    long long lo, hi;
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        // Build lo
        for (long long b = 1, i = low.size()-1; i >= 0; i--, b*=10) lo += (b*(low[i]-'0'));
        // Build hi
        for (long long b = 1, i = high.size()-1; i >= 0; i--, b*=10) hi += (b*(high[i]-'0'));
        // Build strobogrammatic number with length = n
        for (int n = low.size(); n <= high.size(); n++)
            res += backtracking(0, pow(10,n-1), n-1, 1, 0);

        return res;
    }

    int backtracking(int i, long long bi, int j, long long bj, long long sum) {
        if (i > j) return (lo <= sum && sum <= hi)?1:0;

        int res = 0;
        if (i == j) {
            for (int k = 0; k < one.size(); k++) {
                sum += (bi*one[k]);
                res += backtracking(i+1, bi/10, j-1, bj*10, sum);
                sum -= (bi*one[k]);
            }
        } else {
            for (int k = 0; k < two.size(); k++) {
                if (i == 0 && two[k][0] == 0) continue;
                sum += (bi*two[k][0] + bj*two[k][1]);
                res += backtracking(i+1, bi/10, j-1, bj*10, sum);
                sum -= (bi*two[k][0] + bj*two[k][1]);
            }
        }
        return res;
    }
};
