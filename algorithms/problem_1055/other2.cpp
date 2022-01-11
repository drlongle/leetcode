class Solution {
public:
    int shortestWay(string source, string target) {
        vector<bool> charMap(26, false);
        for (auto c: source)
            charMap[c - 'a'] = true;

        int len = target.length();
        int slen = source.length();

        int count = 0;

        for (int i = 0; i < len; )
        {
            char ch = target[i];
            // If ch is not present in source, then bail out
            if (!charMap[ch - 'a'])
                return -1;

            // keep finding the target chars until the order of source string is exhausted
            int spos = source.find(ch, 0);
            while (spos != string::npos && spos < slen)
            {
                ++i;
                ch = target[i];
                // find the next char searching from pos+1 position onwards
                spos = source.find(ch, spos + 1);
            }

            // if the current substring search exhausted source, increment count and repeat with remaining part of target
            ++count;
        }

        return count;
    }
};
