/*
467. Unique Substrings in Wraparound String
Medium

We define the string s to be the infinite wraparound string of
"abcdefghijklmnopqrstuvwxyz", so s will look like this:
"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
Given a string p, return the number of unique non-empty substrings of p are
present in s.

Example 1:
Input: p = "a"
Output: 1
Explanation: Only the substring "a" of p is in s.

Example 2:
Input: p = "cac"
Output: 2
Explanation: There are two substrings ("a", "c") of p in s.

Example 3:
Input: p = "zab"
Output: 6
Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of
p in s.

Constraints:
1 <= p.length <= 10^5
p consists of lowercase English letters.
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

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<int> runs;

    int findSubstringInWraproundString(string p) {
        runs.resize(26, 0);
        for (int i = 0, sz = p.size(); i < sz;) {
            int j = i + 1;
            while (j < sz) {
                if (p[j] - p[j - 1] == 1 || (p[j] == 'a' && p[j - 1] == 'z'))
                    ++j;
                else
                    break;
            }
            int index = p[i] - 'a';
            runs[index] = max(runs[index], j - i);
            i = j;
        }

        for (int i = 0; i < 26; ++i) {
            int run = runs[i];
            for (int j = 1; j < run; ++j) {
                int index = (i + j) % 26;
                runs[index] = max(runs[index], run - j);
            }
        }

        return accumulate(begin(runs), end(runs), 0);
    }
};

int main() {
    Solution sol;
    string p;

    // Expected: 1
    p = "a";
    cout << p << " -> " << sol.findSubstringInWraproundString(p) << endl;

    // Expected: 2
    p = "cac";
    cout << p << " -> " << sol.findSubstringInWraproundString(p) << endl;

    // Expected: 6
    p = "zab";
    cout << p << " -> " << sol.findSubstringInWraproundString(p) << endl;

    return 0;
}
