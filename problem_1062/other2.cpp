class Solution {
public:
    int longestRepeatingSubstring(string S) {
        // We could find the longest length using binary search. Here, we search for all the strings with length
        // S.size() / 2, if we find any substring that occurs more than once, we update the maximum length as S.size() / 2,
        // then search for the substrings whose size is within [S.size() / 2 + 1, S.size()] recursively. Otherwise,
        // search for the substrings whose size is within [1, S.size() / 2 - 1]. Finally, return the newest maximum length.
        return search(S, 1, S.size());
    }

private:
    int search(string S, int left, int right)
    {
        if (left > right)
        {
            return 0;
        }

        int mid = left + (right - left) / 2, size = S.size(), exist = 0;
        unordered_set<string> substrs;
        for (int i = 0; i <= size - mid; ++i)
        {
            string sub = S.substr(i, mid);
            if (substrs.find(sub) != substrs.end())
            {
                exist = 1;
                break;
            }
            substrs.insert(sub);
        }

        if (exist)
        {
            int len = search(S, mid + 1, right);
            return mid >= len ? mid : len;
        }
        return search(S, left, mid - 1);
    }
};
