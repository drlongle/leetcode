/*
1963. Minimum Number of Swaps to Make the String Balanced

You are given a 0-indexed string s of even length n. The string consists of
exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

Example 1:
Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".

Example 2:
Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".

Example 3:
Input: s = "[]"
Output: 0
Explanation: The string is already balanced.

Constraints:
n == s.length
2 <= n <= 10^6
n is even.
s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing
brackets ']' equals n / 2.
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
    int minSwaps(string s) {
        size_t res{0}, i{0}, j{s.size() - 1};
        int open{0}, close{0};
        while (i < j) {
            while (i < j) {
                char c{s[i]};
                open += (c == ']') ? -1 : 1;
                if (open < 0)
                    break;
                ++i;
            }
            while (i < j) {
                char c{s[j]};
                close += (c == '[') ? -1 : 1;
                if (close < 0)
                    break;
                --j;
            }
            if (i < j) {
                swap(s[i], s[j]);
                ++res;
                open = 1;
                close = 1;
                ++i, --j;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s;

    s = "][][";
    cout << sol.minSwaps(s) << endl;

    s = "]]][[[";
    cout << sol.minSwaps(s) << endl;

    s = "[]";
    cout << sol.minSwaps(s) << endl;

    return 0;
}
