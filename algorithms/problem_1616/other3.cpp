class Solution {
public:
    bool isPalindrome(string a)
    {
        for (int l = 0, r = a.size() - 1; l < r; ++l, --r)
            if (a[l] != a[r])
                return false;

        return true;
    }

    bool formsPalindrome(string a, string b)
    {
        int l = 0, r = b.size() - 1;
        for (; l < r && a[l] == b[r]; ++l, --r);

        return isPalindrome(a.substr(l, r - l + 1)) ||
               isPalindrome(b.substr(l, r - l + 1));
    }

    bool checkPalindromeFormation(string a, string b)
    {
        return formsPalindrome(a, b) || formsPalindrome(b, a) ||
               formsPalindrome(a, a) || formsPalindrome(b, b);
    }
};