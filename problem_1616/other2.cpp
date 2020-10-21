/*
Greedily use all matching letters from suffix and prefix. Then check if the middle of either string is
a palindrome. This logic can be easily proven by a contradiction.

Another way to think about this: using more characters from the both strings "shrinks" the middle part,
so it increases the chance that the middle part is a palindrome.

Note that we do this twice - once for a] + [b, and once for b] + [a.
*/

class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j])
            ++i, --j;
        return i >= j;
    }
    bool check(string &a, string &b) {
        int i = 0, j = a.size() - 1;
        while (i < j && a[i] == b[j])
            ++i, --j;
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};