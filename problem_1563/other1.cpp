class Solution {
public:
    int stoneGameV(vector<int>& stoneValue)
    {
        vector<int> sums { 0 };
        partial_sum(stoneValue.begin(), stoneValue.end(), back_inserter(sums));
        vector<vector<int>> memo(sums.size(), vector<int>(sums.size(), -1));
        return dfs(sums, 1, sums.size() - 1, memo);
    }

    int dfs(vector<int>& sums, int left, int right, vector<vector<int>>& memo)
    {
        if (left >= right)
            return 0;

        if (memo[left][right] != -1)
            return memo[left][right];

        int result = 0;

        for (int i = left; i <= right; ++i)
        {
            auto leftSum = sums[i] - sums[left - 1];
            auto rightSum = sums[right] - sums[i];

            if (leftSum <= rightSum)
                result = max(result, leftSum + dfs(sums, left, i, memo));


            if (leftSum >= rightSum)
                result = max(result, rightSum + dfs(sums, i + 1, right, memo));
        }

        return memo[left][right] = result;
    }
};