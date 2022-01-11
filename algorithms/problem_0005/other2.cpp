// Manacher's solution

class Solution {
public:
    string longestPalindrome(string s)
    {
        string res;
        if (s.empty())
            return res;

        string str("#");
        for (int i = 0; i < s.size(); i++)
        {
            str.push_back(s[i]);
            str.push_back('#');
        }

        vector<int> p(str.size());

        int mx = 0;

        for (int i = 0; i < str.size(); i++)
        {
            if (i < (mx + p[i]))
            {
                p[i] = p[2 * mx - i];
            }

            while (p[i] + i < str.size() && i - p[i] >= 0 && str[i - p[i]] == str[i + p[i]])
                p[i]++;

            if (i + p[i] > mx + p[mx])
                mx = i;
        }

        int max_len = 0, max_pos = 0;

        for (int i = 0; i < p.size(); i++)
        {
            if (max_len < p[i])
            {
                max_pos = i / 2;
                max_len = p[i] - 1;
            }
        }

        return s.substr(max_pos - (max_len)/2 , max_len);
    }
};
