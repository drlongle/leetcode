class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> subs;
        for (auto i = 0; i < nums.size(); ++i)
            for (auto j = i, sum = 0; j < nums.size(); ++j)
                subs.push_back(sum += nums[j]);
        partial_sort(begin(subs), begin(subs) + left, end(subs));
        partial_sort(begin(subs) + left, begin(subs) + right, end(subs));
        return accumulate(begin(subs) + left - 1, begin(subs) + right, 0, [](int s, int i) { return (s + i) % 1000000007; });
    }
};