class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1, s.length() - 2);
        vector<string> result;
        for (int i = 1; i < s.length(); i++)
        {
            string str1 = s.substr(0, i), str2 = s.substr(i);
            vector<string> res1 = genValid(str1), res2 = genValid(str2);

            for (auto& s1 : res1)
                for (auto& s2 : res2)
                    genResult(s1, s2, result);
        }

        return result;
    }

    vector<string> genValid(string& str)
    {
        vector<string> res;
        if (valid(str))
            res.push_back(str);

        for (int i = 1; i < str.length(); i++)
        {
            string cur = str.substr(0, i) + "." + str.substr(i);
            if (valid(cur))
                res.emplace_back(cur);
        }

        return res;
    }

    bool valid(string& str)
    {
        if (str.length() > 1 && str[0] == '0' && str[1] != '.')
            return false;

        if (str.back() == '0')
        {
            for (int i = str.length() - 1; i >= 0; i--)
                if (str[i] == '.')
                    return false;
        }

        return true;
    }

    void genResult(string& str1, string& str2, vector<string>& result)
    {
        result.emplace_back("(" + str1 + ", " + str2 + ")");
    }
};
