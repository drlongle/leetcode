class Solution {
public:
    int stoneGameVII(vector<int> &stones) {
        int n = stones.size();
        vector<int> prefixSum(n + 1);
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }
        return abs(findDifference(memo, prefixSum, 0, n - 1, true));
    }

    int findDifference(vector<vector<int>> &memo, vector<int> &prefixSum,
                       int start, int end, bool alice) {
        if (start == end) {
            return 0;
        }
        if (memo[start][end] != INT_MAX) {
            return memo[start][end];
        }
        int difference;
        int scoreRemoveFirst = prefixSum[end + 1] - prefixSum[start + 1];
        int scoreRemoveLast = prefixSum[end] - prefixSum[start];

        if (alice) {
            difference =
                    max(findDifference(memo, prefixSum, start + 1, end, !alice) +
                        scoreRemoveFirst,
                        findDifference(memo, prefixSum, start, end - 1, !alice) +
                        scoreRemoveLast);
        } else {
            difference =
                    min(findDifference(memo, prefixSum, start + 1, end, !alice) -
                        scoreRemoveFirst,
                        findDifference(memo, prefixSum, start, end - 1, !alice) -
                        scoreRemoveLast);
        }
        memo[start][end] = difference;

        return difference;
    }
};