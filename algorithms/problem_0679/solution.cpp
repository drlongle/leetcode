/*
679. 24 Game
Hard

You are given an integer array cards of length 4. You have four cards, each
containing a number in the range [1, 9]. You should arrange the numbers on these
cards in a mathematical expression using the operators ['+', '-', '*', '/'] and
the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

The division operator '/' represents real division, not integer division.
For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
Every operation done is between two numbers. In particular, we cannot use '-' as
a unary operator. For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 -
1 - 1" is not allowed. You cannot concatenate numbers together For example, if
cards = [1, 2, 1, 2], the expression "12 + 12" is not valid. Return true if you
can get such expression that evaluates to 24, and false otherwise.

Example 1:
Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24

Example 2:
Input: cards = [1,2,1,2]
Output: false

Constraints:
cards.length == 4
1 <= cards[i] <= 9
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
    static constexpr int n = 4;
    static constexpr double epsilon = 0.00001;

    vector<vector<set<double>>> dp;
    vector<int> nums;
    bitset<4> mask;

    bool permute(vector<int> &cards, int level) {
        if (level == n && check24(nums)) {
            return true;
        }

        for (int i = 0; i < n; ++i) {
            if (!mask.test(i)) {
                mask.set(i);
                nums[level] = cards[i];
                if (permute(cards, level + 1))
                    return true;
                mask.reset(i);
            }
        }

        return false;
    }

    bool judgePoint24(vector<int> &cards) {
        for (int i = 0; i < n; ++i)
            mask.reset(i);
        nums.resize(4);
        return permute(cards, 0);
    }

    bool check24(vector<int> &cards) {
        dp.clear();
        dp.resize(n, vector<set<double>>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i].insert(cards[i]);
        }

        for (int l = 2; l <= 4; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int limit = i + l - 1;
                for (int j = i + 1; j <= limit; ++j) {
                    auto &set_a = dp[i][j - 1];
                    auto &set_b = dp[j][limit];
                    for (auto a : set_a) {
                        for (auto &b : set_b) {
                            if (l == 4) {
                                if (abs(a + b - 24.0) < epsilon ||
                                    abs(a * b - 24.0) < epsilon ||
                                    abs(a - b - 24.0) < epsilon ||
                                    (b != 0 && abs(a / b - 24.0) < epsilon))
                                    return true;

                            } else {
                                dp[i][limit].insert(a + b);
                                dp[i][limit].insert(a - b);
                                dp[i][limit].insert(a * b);
                                if (b)
                                    dp[i][limit].insert(a / b);
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> cards;

    cards = {4, 1, 8, 7};
    cout << boolalpha << sol.judgePoint24(cards) << endl;

    cards = {1, 2, 1, 2};
    cout << boolalpha << sol.judgePoint24(cards) << endl;

    return 0;
}
