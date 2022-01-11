/*
 420. Strong Password Checker

    Total Accepted: 60
    Total Submissions: 319
    Difficulty: Hard

A password is considered strong if below conditions are all met:

    It has at least 6 characters and at most 20 characters.
    It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
    It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion and replace of any one character are all considered as one change.
*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

/*
If the length of string is 3 or less, only insertion is needed;
If the length is 4, two insertions and might one replacement are needed;
if the length is 5, one insertion and might two replacements are needed.
So it's easy to solve for the case that length is less than 6: Math.Max(requiredChar, 6 - s.Length); The requiredChar is at most 3.

For the case, 6<=length<=20, only replacements are needed.

If length is greater than 20, only replacements and deletions are needed.
For the case of a repeated substring which length is mutiple of 3 (note 3n, e.g. "aaa"), then one deletion will save a replacement to fix it;
For the case of a repeated substring which length is mutiple of 3 plus 1 (note 3n+1, e.g. "aaaa"), then two deletions will save a replacement to fix it;
For the case of a repeated substring which length is mutiple of 3 plus 2 (note 3n+2, e.g. "aaaaa"), then three deletions will save a replacement to fix it;
*/

class Solution {
public:
    int strongPasswordChecker(string s) {
        int needUpperCase = count_if(begin(s), end(s), [](char& c) { return isupper(c);}) == 0;
        int needLowerCase = count_if(begin(s), end(s), [](char& c) { return islower(c);}) == 0;
        int needDigits = count_if(begin(s), end(s), [](char& c) { return isdigit(c);}) == 0;
        int requiredChars = needUpperCase + needLowerCase + needDigits;
        int ssize = s.size();

        if (ssize < 6)
            return max(6 - ssize, requiredChars);

        // only need replacement and deletion now when s.Length >= 6
        int replace = 0; // total replacements for repeated chars. e.g. "aaa" needs 1 replacement to fix

        int oned = 0; // total deletions for 3n repeated chars. e.g. "aaa" needs 1 deletion to fix

        int twod = 0; // total deletions for 3n+1 repeated chars. e.g. "aaaa" needs 2 deletions to fix.

        for (int i = 0; i < ssize; ) {
            char current = s[i];
            int len = 1;
            while (len < ssize && s[i + len] == current)
                ++len;
            if (len >= 3) {
                replace += len / 3;
                switch (len % 3) {
                case 0:
                    ++oned;
                    break;
                case 1:
                    twod += 2;
                    break;
                }
            }
            i += len;
        }

        // no need deletion when s.Length <= 20
        if (ssize <= 20)
            return max(replace, requiredChars);

        int deleteCount = ssize - 20;

        // deleting 1 char in (3n) repeated chars will save one replacement
        replace -= min(deleteCount, oned);

        // deleting 2 chars in (3n+1) repeated chars will save one replacement
        replace -= min(max(deleteCount - oned, 0), twod) / 2;

        // deleting 3 chars in (3n+2) repeated chars will save one replacement
        replace -= max(deleteCount - oned - twod, 0) / 3;

        return deleteCount + max(requiredChars, replace);
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    string s;

    // Expected: 2
    s = "aaa111";

    // Expected : 3
    //s = "1111111111";

    // Expected: 2
    //s = "ABABABABABABABABABAB1";

    // Expected: 7
    // 31 / 42 test cases passed.
    //s = "aaaaaaaaaaaaaaaaaaaaa";

    // Expected: 2
    // 31 / 42 test cases passed
    //s = "1010101010aaaB10101010";

    // Expected: 3
    //s = "abababababababababaaa";

    // Expected: 3
    //s = "...";

    // Expected: 3
    // 33 / 42 test cases passed
    s = "1234567890123456Baaaaa";

    // Expected: 3
    // 37 / 42 test cases passed.
    //s = "aaaabbaaabbaaa123456A";

    // Expected: 2
    // 38 / 42 test cases passed.
    //s = "1Abababcaaaabababababa";

    cout << s << " -> " << sol.strongPasswordChecker(s) << endl;

    return 0;
}

