/*
1616. Split Two Strings to Make Palindrome
Medium

You are given two strings a and b of the same length. Choose an index and split both strings at the same index,
splitting a into two strings: aprefix and asuffix where a = aprefix + asuffix, and splitting b into two strings:
bprefix and bsuffix where b = bprefix + bsuffix. Check if aprefix + bsuffix or bprefix + asuffix forms a
palindrome.

When you split a string s into sprefix and ssuffix, either ssuffix or sprefix is allowed to be empty.
For example, if s = "abc", then "" + "abc", "a" + "bc", "ab" + "c" , and "abc" + "" are valid splits.

Return true if it is possible to form a palindrome string, otherwise return false.

Notice that x + y denotes the concatenation of strings x and y.

Example 1:
Input: a = "x", b = "y"
Output: true
Explaination: If either a or b are palindromes the answer is true since you can split in the following way:
aprefix = "", asuffix = "x"
bprefix = "", bsuffix = "y"
Then, aprefix + bsuffix = "" + "y" = "y", which is a palindrome.

Example 2:
Input: a = "abdef", b = "fecab"
Output: true

Example 3:
Input: a = "ulacfd", b = "jizalu"
Output: true
Explaination: Split them at index 3:
aprefix = "ula", asuffix = "cfd"
bprefix = "jiz", bsuffix = "alu"
Then, aprefix + bsuffix = "ula" + "alu" = "ulaalu", which is a palindrome.

Example 4:
Input: a = "xbdef", b = "xecab"
Output: false

Constraints:
1 <= a.length, b.length <= 105
a.length == b.length
a and b consist of lowercase English letters
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

    bool check(string& a, string& b) {
        bool path1 = true, path2 = true, path3 = true;
        for (int i = 0, j = n - 1; i < j && (path1 || path2 || path3); ++i, --j) {
            path1 &= a[i] == a[j];
            path3 &= b[i] == b[j];
            if (path2 && a[i] != b[j]) {
                path2 = false, path1 = true, path3 = true;
                --i, ++j;
            }
        }

        return path1 || path2 || path3;
    }

    int n;
    bool checkPalindromeFormation(string a, string b) {
        n = a.size();
        return check(a, b) || check(b, a);
    }
};

int main() {
    Solution sol;
    string a, b;

    // true
    a = "cde21", b = "123ab";
    cout << boolalpha << sol.checkPalindromeFormation(a, b) << endl;

    // true
    a = "cdea1", b = "1232b";
    cout << boolalpha << sol.checkPalindromeFormation(a, b) << endl;

    // true
    a = "cdeay21", b = "12343bx";
    cout << boolalpha << sol.checkPalindromeFormation(a, b) << endl;

    // true
    a = "x", b = "y";
    cout << boolalpha << sol.checkPalindromeFormation(a, b) << endl;

    // Output: true
    a = "abdef", b = "fecab";
    cout << boolalpha << sol.checkPalindromeFormation(a, b) << endl;

    // Output: true
    a = "ulacfd", b = "jizalu";
    cout << boolalpha << sol.checkPalindromeFormation(a, b) << endl;

    // Output: false
    a = "xbdef", b = "xecab";
    cout << boolalpha << sol.checkPalindromeFormation(a, b) << endl;

    // false
    a = "abda", b = "acmc";
    cout << boolalpha << sol.checkPalindromeFormation(a, b) << endl;

    // true
    a = "pvhmupgqeltozftlmfjjde", b = "yjgpzbezspnnpszebzmhvp";
    cout << boolalpha << sol.checkPalindromeFormation(a, b) << endl;

    // false
    a = "abccef", b = "cgdhga";
    cout << boolalpha << sol.checkPalindromeFormation(a, b) << endl;

    return 0;
}
