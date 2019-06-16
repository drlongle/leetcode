/*
1092. Shortest Common Supersequence
Difficulty: Hard

Given two strings str1 and str2, return the shortest string that has both
str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T
(possibly 0, and the characters are chosen anywhere from T) results in the string S.)
 
Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a substring of "cabac" because we can delete the first "c".
str2 = "cab" is a substring of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    string superSequence(const string& s1, int index1, const string& s2, int index2) {
        if (index1 == static_cast<int>(s1.size()))
            return s2.substr(index2);
        if (index2 == static_cast<int>(s2.size()))
            return s1.substr(index1);
        if (s1[index1] == s2[index2])
            return string(1, s1[index1]) + superSequence(s1, index1+1, s2, index2+1);
        string super1 = string(1, s1[index1]) + superSequence(s1, index1+1, s2, index2);
        string super2 = string(1, s2[index2]) + superSequence(s1, index1, s2, index2+1);

        return (super1.size() < super2.size()) ? super1 : super2;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        return superSequence(str1, 0, str2, 0);
    }
};

int main() {
    Solution sol;
    string str1, str2;

    // Expected: "cabac"
    str1 = "abac", str2 = "cab";

    // 28 / 47 test cases passed.
    str1 = "bcaaacbbbcbdcaddadcacbdddcdcccdadadcbabaccbccdcdcbcaccacbbdcbabb";
    str2 = "dddbbdcbccaccbababaacbcbacdddcdabadcacddbacadabdabcdbaaabaccbdaa";

    cout << "Result: " << sol.shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}

