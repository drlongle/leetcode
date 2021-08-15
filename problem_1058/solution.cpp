/*
1058. Minimize Rounding Error to Meet Target
Medium

Given an array of prices [p1,p2...,pn] and a target, round each price pi to Roundi(pi) so that the rounded array
[Round1(p1),Round2(p2)...,Roundn(pn)] sums to the given target. Each operation Roundi(pi) could be either
Floor(pi) or Ceil(pi).

Return the string "-1" if the rounded array is impossible to sum to target. Otherwise, return the smallest
rounding error, which is defined as Σ |Roundi(pi) - (pi)| for i from 1 to n, as a string with three places
after the decimal.

Example 1:
Input: prices = ["0.700","2.800","4.900"], target = 8
Output: "1.000"
Explanation:
Use Floor, Ceil and Ceil operations to get (0.7 - 0) + (3 - 2.8) + (5 - 4.9) = 0.7 + 0.2 + 0.1 = 1.0 .

Example 2:
Input: prices = ["1.500","2.500","3.500"], target = 10
Output: "-1"
Explanation: It is impossible to meet the target.

Example 3:
Input: prices = ["1.500","2.500","3.500"], target = 9
Output: "1.500"

Constraints:
1 <= prices.length <= 500
Each string prices[i] represents a real number in the range [0.0, 1000.0] and has exactly 3 decimal places.
0 <= target <= 10^6
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

#define for_loop(n) for(int i = 0; i < n; ++i)

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        deque<int> fractions;
        int sum = 0;
        target *= 1000;
        for(auto& price: prices) {
            int d = round(stod(price) * 1000);
            sum += d;
            int f = d / 1000 * 1000;
            if (f < d)
                fractions.push_back(d - f);
        }

        sort(begin(fractions), end(fractions));
        int error = 0;
        while (fractions.size()) {
            if (sum < target) {
                int f = fractions.back();
                fractions.pop_back();
                f = 1000 - f;
                sum += f;
                error += f;
            } else {
                int f = fractions.front();
                fractions.pop_front();
                sum -= f;
                error += f;
            }
        }

        if (sum == target) {
            if (!error) return "0.000";
            string res = to_string(error);
            res.insert(res.size() - 3, 1, '.');
            return res;
        } else
            return "-1";
    }
};

int main() {
    Solution sol;

    return 0;
}
