/*
944. Delete Columns to Make Sorted
Easy

You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:

abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

Return the number of columns that you will delete. 

Example 1:
Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.

Example 2:
Input: strs = ["a","b"]
Output: 0
Explanation: The grid looks as follows:
  a
  b
Column 0 is the only column and is sorted, so you will not delete any columns.

Example 3:
Input: strs = ["zyx","wvu","tsr"]
Output: 3
Explanation: The grid looks as follows:
  zyx
  wvu
  tsr
All 3 columns are not sorted, so you will delete all 3.

Constraints:
n == strs.length
1 <= n <= 100
1 <= strs[i].length <= 1000
strs[i] consists of lowercase English letters.
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
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int sz = strs[0].size();
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j][i] < strs[j-1][i]) {
                    ++res;
                    break;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> strs;

    // Output: 1
    strs =  {"cba","daf","ghi"};
    cout << sol.minDeletionSize(strs) << endl;

    // Output: 0
    strs = {"a","b"};
    cout << sol.minDeletionSize(strs) << endl;

    // Output: 3
    strs = {"zyx","wvu","tsr"};
    cout << sol.minDeletionSize(strs) << endl;

    // Output: 1
    strs = {"qowfc","spyge","sqbif","vvrkk"};
    cout << sol.minDeletionSize(strs) << endl;

    return 0;
}
