// KMP, LPS table, O(N^2)

class Solution {
public:
    int countDistinct(string s) {
        int n = s.size();
        int res = 0;
        for (int j = n - 1; j >= 0; --j)
        {
            int m = n - j;
            vector<int> lps(m, 0);
            int len = 0;
            int i = 1;
            int maxVal = 0;
            while (i < m)
            {
                if (s[j + len] == s[j + i])
                {
                    ++len;
                    lps[i] = len;
                    maxVal = max(maxVal, len);
                    ++i;
                }
                else
                {
                    if (len > 0)
                    {
                        len = lps[len - 1];
                    }
                    else
                    {
                        lps[i] = 0;
                        ++i;
                    }
                }
            }
            res += m - maxVal;
        }

        return res;
    }
};
