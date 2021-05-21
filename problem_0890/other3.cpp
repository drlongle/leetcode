class Solution {
public:
    bool areIsomorphic(string str1, string str2)
    {
        int m = str1.length(), n = str2.length();
        if (m != n)
            return false;
        bool marked[256] = {false};

        int map[256];
        memset(map, -1, sizeof(map));

        for (int i = 0; i < n; i++)
        {

            if (map[str1[i]] == -1)
            {
                if (marked[str2[i]] == true)
                    return false;

                marked[str2[i]] = true;

                map[str1[i]] = str2[i];
            }

            else if (map[str1[i]] != str2[i])
                return false;
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            if(areIsomorphic(words[i] , pattern)==true)
                ans.push_back(words[i]);
            else
                continue;
        }
        return ans;
    }
};
