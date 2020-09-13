/*
1576. Replace All ?'s to Avoid Consecutive Repeating Characters
Easy

Given a string s containing only lower case English letters and the '?' character, convert all the '?' characters
into lower case letters such that the final string does not contain any consecutive repeating characters.
You cannot modify the non '?' characters.

It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.

Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution,
return any of them. It can be shown that an answer is always possible with the given constraints.

Example 1:
Input: s = "?zs"
Output: "azs"
Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid
modification as the string will consist of consecutive repeating characters in "zzs".

Example 2:
Input: s = "ubv?w"
Output: "ubvaw"
Explanation: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings
will consist of consecutive repeating characters in "ubvvw" and "ubvww".

Example 3:
Input: s = "j?qg??b"
Output: "jaqgacb"

Example 4:
Input: s = "??yw?ipkj?"
Output: "acywaipkja"

Constraints:
1 <= s.length <= 100
s contains only lower case English letters and '?'.
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
    string modifyString(string s) {
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            if (s[i] == '?') {
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if ((i > 0 && s[i-1] == ch) || (i < sz-1 && s[i+1] == ch))
                        continue;
                    s[i] = ch;
                    break;
                }
            }
        }

        return s;
    }
};

int main() {
    Solution sol;

    return 0;
}
