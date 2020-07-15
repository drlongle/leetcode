class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int count[101] = {};
        for (auto n : nums)
            ++count[n];
        return accumulate(begin(count), end(count), 0, [](int s, int i) { return s + i * (i - 1) / 2; });
    }
};