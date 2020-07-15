class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int cnt[101] = {};
        for (auto n : nums)
            ++cnt[n];
        return accumulate(begin(cnt), end(cnt), 0, [](int s, int i) { return s + i * (i - 1) / 2; });
    }
};