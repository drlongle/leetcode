/*
848. Shifting Letters
Medium

You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.

Example 1:
Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.

Example 2:
Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
shifts.length == s.length
0 <= shifts[i] <= 10^9
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for (int sz = s.size(), i = sz - 1, cnt = 0; i >= 0; --i) {
            cnt = (cnt + shifts[i]) % 26;
            int c = s[i] - 'a';
            s[i] = 'a' + (c + cnt) % 26;
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<int> shifts;
    string s;

    // Output: "rpl"
    s = "abc", shifts = {3,5,9};
    cout << sol.shiftingLetters(s, shifts) << endl;

    // Output: "gfd"
    s = "aaa", shifts = {1,2,3};
    cout << sol.shiftingLetters(s, shifts) << endl;

    return 0;
}
