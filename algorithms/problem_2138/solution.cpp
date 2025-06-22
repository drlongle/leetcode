/*
2138. Divide a String Into Groups of Size k
Easy

A string s can be partitioned into groups of size k using the following procedure:

The first group consists of the first k characters of the string, the second group consists
of the next k characters of the string, and so on. Each element can be a part of exactly one
group. For the last group, if the string does not have k characters remaining, a character
fill is used to complete the group. Note that the partition is done so that after removing
the fill character from the last group (if it exists) and concatenating all the groups in
order, the resultant string should be s.

Given the string s, the size of each group k and the character fill, return a string array
denoting the composition of every group s has been divided into, using the above procedure.

Example 1:
Input: s = "abcdefghi", k = 3, fill = "x"
Output: ["abc","def","ghi"]
Explanation:
The first 3 characters "abc" form the first group.
The next 3 characters "def" form the second group.
The last 3 characters "ghi" form the third group.
Since all groups can be completely filled by characters from the string, we do not need
to use fill. Thus, the groups formed are "abc", "def", and "ghi".

Example 2:
Input: s = "abcdefghij", k = 3, fill = "x"
Output: ["abc","def","ghi","jxx"]
Explanation:
Similar to the previous example, we are forming the first three groups "abc", "def", and "ghi".
For the last group, we can only use the character 'j' from the string. To complete this group,
we add 'x' twice. Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".

Constraints:
1 <= s.length <= 100
s consists of lowercase English letters only.
1 <= k <= 100
fill is a lowercase English letter.
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int sz = s.size();
        vector<string> res;
        for (int i = 0; i < sz/k; i++) {
            res.push_back(s.substr(i*k, k));
        }
        if (sz % k != 0) {
            int i = sz / k;
            res.push_back(s.substr(i*k, min(k, sz - i*k)));
            while (res.back().size() < k) {
                res.back().push_back(fill);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;
    int k;
    char fill;
    vector<string> res;

    s = "abcdefghi", k = 3, fill = 'x';
    res = sol.divideString(s, k, fill);
    copy(res.begin(), res.end(), ostream_iterator<string>(cout, " "));

    s = "abcdefghij", k = 3, fill = 'x';
    res = sol.divideString(s, k, fill);
    copy(res.begin(), res.end(), ostream_iterator<string>(cout, " "));

    return 0;
}
