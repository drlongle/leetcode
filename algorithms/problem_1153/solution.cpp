/*
1153. String Transforms Into Another String
Hard

Given two strings str1 and str2 of the same length, determine whether you can transform
str1 into str2 by doing zero or more conversions.

In one conversion you can convert all occurrences of one character in str1 to any other
lowercase English character.

Return true if and only if you can transform str1 into str2.

Example 1:
Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.

Example 2:
Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        map<char, set<char>> mapping;
        set<char> s2;
        int len = str1.size();
        for (int i = 0; i < len; ++i) {
            mapping[str1[i]].emplace(str2[i]);
            if (mapping[str1[i]].size() > 1)
                return false;
            s2.emplace(str2[i]);
        }
        if (mapping.size() == 26)
            return s2.size() != 26;
        return true;
    }
};

int main()
{
    Solution sol;
    string str1, str2;

    // Expected: true
    str1 = "aabcc", str2 = "ccdee";

    // Expected: false
    //str1 = "leetcode", str2 = "codeleet";
    
    // Expected: false
    //str1 = "abcdefghijklmnopqrstuvwxyz";
    //str2 = "bcdefghijklmnopqrstuvwxyza";

    // Expected: true
    //str1 = "abcdefghijklmnopqrstuvwxy";
    //str2 = "bcdefghijkamnopqrstuvwxyz";

    // 32 / 36 test cases passed.
    // Expected: true
    //str1 = "abcdefghijklmnopqrstuvwxyz";
    //str2 = "bcdefghijklmnopqrstuvwxyzq";

    // 35 / 36 test cases passed.
    // Expected: true
    str1 = "abcdefghijklmnopqrstuvwxy";
    str2 = "bcdefghijkamnopqrstuvwxyz";
    
    cout << "Result: " << sol.canConvert(str1, str2) << endl;
    
    return 0;
}

