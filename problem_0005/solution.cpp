/*
5. Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string expand_palindrome(const string& s, int left, int right)
{
    int len = s.length();
    while(left >= 0 && right <= len -1 && s[left] == s[right])
    {
        --left;
        ++right;
    }
    return s.substr(left+1, right-left-1);
}

string longest_palindromes(const string& s)
{
    unsigned int len = s.length();
    if (len == 0)
        return "";

    string result = s.substr(0, 1);
    for (unsigned int i = 0; i < len-1; i++)
    {
        string temp = expand_palindrome(s, i, i);
        if (temp.length() > result.length())
            result = temp;

        temp = expand_palindrome(s, i, i+1);
        if (temp.length() > result.length())
            result = temp;
    }

    return result;
}


class Solution {
public:

    bool test(string& s, int low_index, int len, vector<vector<bool> >& cache)
    {
        if (len < 0)
            return false;
        int high_index = low_index + len - 1;
        if (s[low_index] != s[high_index])
            return false;
        if (len == 1 || len == 2)
        {
            cache[low_index][len] = true;
            return true;
        }
        if (cache[low_index+1][len-2] == false)
            return false;
        cache[low_index][len] = true;
        return true;
    }

    string longestPalindrome(string s) {
        if (s.empty())
            return string();
        vector<vector<bool > > cache(s.size(), vector<bool>(s.size(), false));
        string result = s.substr(0, 1);

        for (int len = 2; len <= static_cast<int>(s.size()); ++len)
            for (int j = 0; j < static_cast<int>(s.size()); ++j)
            {
                int low_index = j;
                int high_index = j + len -1;
                if (high_index < static_cast<int>(s.size())) {
                    bool testresult = test(s, low_index, len, cache);
                    if (testresult && len > static_cast<int>(result.size())) {
                        result = s.substr(j, len);
                    }
                }
            }

        return result;
    }
};

int main()
{
    Solution solution;
    string s = "PAYPALISHIRING";
    s = "uabbaf";

    cout << solution.longestPalindrome(s);
}

