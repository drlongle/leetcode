class Solution
{
public:
    int minSumOfLengths(vector<int> &arr, int target)
    {
        vector<int> dp(arr.size() + 1, INT_MAX);
        int result = INT_MAX;

        for (int start = 1, index = 1, sum = 0; index <= arr.size(); ++index)
        {
            sum += arr[index - 1];
            dp[index] = dp[index - 1];

            while (start < index && sum > target)
                sum -= arr[start++ - 1];

            if (sum == target)
            {
                if (dp[start - 1] != INT_MAX)
                    result = min(result, dp[start - 1] + index - start + 1);
                dp[index] = min(dp[index], index - start + 1);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};