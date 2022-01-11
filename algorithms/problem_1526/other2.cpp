class Solution
{
public:
    int minNumberOperations(vector<int> &t)
    {
        int res = t[0];
        for (int i = 1; i < t.size(); ++i)
            res += max(0, t[i] - t[i - 1]);
        return res;
    }
};