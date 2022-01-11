class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0, end = s.size() - 1;
        while (begin <= end) {
            for (; begin <= end; ++begin)
                if (isalnum(s[begin]))
                    break;
            for (; begin <= end; --end)
                if (isalnum(s[end]))
                    break;
            if (begin <= end && tolower(s[begin]) != tolower(s[end]))
                return false;
            ++begin, --end;
        }
        return true;
    }
};
