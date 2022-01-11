/*
423. Reconstruct Original Digits from English

    Difficulty: Medium

Given a non-empty string containing an out-of-order English representation of
digits 0-9, output the digits in ascending order.

Note:
 Input contains only lowercase English letters.
 Input is guaranteed to be valid and can be transformed to its original digits.
 That means invalid inputs such as "abc" or "zerone" are not permitted.
 Input length is less than 50,000.

Example 1:

Input: "owoztneoer"

Output: "012"

Example 2:

Input: "fviefuro"

Output: "45"

 */

#include <algorithm>
#include <array>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    map<int, string> digits{ {0, "zero"}, {1, "one"}, {2, "two"},
        {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"},
        {8, "eight"}, {9, "nine"} };
    map<int, unordered_map<char, int>> digitCounts;
    vector<unordered_map<char,int>> unique{
        { {'z', 0}, {'w', 2}, {'x', 6}, {'g', 8} },
        { {'h', 3}, {'s', 7} },
        { {'v', 5}, {'r', 4} },
        { {'o', 1}, {'i', 9} } };

    bool containsDigit(unordered_map<char, int>& charCounts, int digit) {
        unordered_map<char, int>& counts = digitCounts[digit];

        for (auto& p: counts) {
            auto it = charCounts.find(p.first);
            if (it == charCounts.end() || it->second < p.second)
                return false;
        }
        return true;
    }

    void removeDigit(unordered_map<char, int>& charCounts, int digit) {
        unordered_map<char, int>& counts = digitCounts[digit];

        for (auto& p: counts) {
            charCounts[p.first] -= p.second;
            if (charCounts[p.first] == 0)
                charCounts.erase(p.first);
        }
    }

    string originalDigits(string s) {
        unordered_map<char, int> charCounts;
        string result;

        for (char c: s)
            ++charCounts[c];

        for (auto& p: digits) {
            unordered_map<char, int>& m = digitCounts[p.first];
            cout << p.first << ", " << p.second << endl;
            for (char c: p.second) {
                ++m[c];
            }
        }
        for (size_t i = 0; i < unique.size(); ++i) {
            unordered_map<char, int>& m = unique[i];
            for (auto& p: m) {
                while (containsDigit(charCounts, p.second)) {
                    result.push_back('0' + p.second);
                    removeDigit(charCounts, p.second);
                }
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;

    string s;

    // Expected: "012"
    s = "owoztneoer";

    // Expected: "45"
    //s = "fviefuro";

    // Output:   "01113356"
    // Expected: "0123456789"
    s = "zeroonetwothreefourfivesixseveneightnine";

    cout << s << " -> " << sol.originalDigits(s) << endl;

    return 0;
}

