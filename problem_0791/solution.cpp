/*
791. Custom Sort String
Medium

S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input:
S = "cba"
T = "abcd"
Output: "cbad"
Explanation:
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.

Note:
S has length at most 26, and no character is repeated in S.
T has length at most 200.
S and T consist of lowercase letters only.
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
    string customSortString(string S, string T) {
        vector<int> cnt(26, 0);
        for (char ch: T) {
            ++cnt[ch - 'a'];
        }

        ostringstream oss;
        for (char ch: S) {
            int index = ch - 'a';
            if (cnt[index] > 0) {
                oss << string(cnt[index], ch);
                cnt[index] = 0;
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0)
            oss << string(cnt[i], 'a' + i);
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    string S, T;

    // Output: "cbad"
    S = "cba";
    T = "abcd";
    cout << sol.customSortString(S, T) << endl;

    return 0;
}
