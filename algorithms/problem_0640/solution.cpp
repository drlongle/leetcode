/*
640. Solve the Equation
Medium

Solve a given equation and return the value of 'x' in the form of a string "x=#value".
The equation contains only '+', '-' operation, the variable 'x' and its coefficient.
You should return "No solution" if there is no solution for the equation,
or "Infinite solutions" if there are infinite solutions for the equation.

If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.

Example 1:
Input: equation = "x+5-3+x=6+x-2"
Output: "x=2"

Example 2:
Input: equation = "x=x"
Output: "Infinite solutions"

Example 3:
Input: equation = "2x=x"
Output: "x=0"

Constraints:
3 <= equation.length <= 1000
equation has exactly one '='.
equation consists of integers with an absolute value in the range [0, 100] without any
leading zeros, and the variable 'x'. The input is generated that
if there is a single solution, it will be an integer.
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

struct Side {
    int val;
    int x;
};

Side parse(string s) {
    Side n{0, 0};
    int i = 0; int sz = s.size();
    int sign = 1;
    while (i < sz) {
        char c = s[i++];
        if (c == '+') {
            continue;
        }
        if (c == '-') {
            sign = -1;
            continue;
        }

        if (c == 'x') {
            n.x += sign;
            sign = 1;
            continue;
        }

        int t = c - '0';
        while (i < sz && s[i] >= '0' && s[i] <= '9') {
            t = t * 10 + s[i++] - '0';
        }
        if (i  < sz && s[i] == 'x') {
            n.x += t * sign;
            ++i;
        } else {
            n.val += sign * t;
        }
        sign = 1;
    }

    return n;
}

class Solution {
public:
    string solveEquation(string equation) {
        int i = equation.find('=');
        auto left = parse(equation.substr(0, i));
        auto right = parse(equation.substr(i + 1));
        left.x -= right.x;
        right.val -= left.val;
        if (left.x != 0) {
            right.val /= left.x;
            return "x=" + to_string(right.val);
        } else if (right.val != 0) {
            return "No solution";
        } else {
            return "Infinite solutions";
        }

        return "";
    }
};

int main() {
    Solution sol;
    string s;

    s = "x+5-311+x=6+x-2";
    cout <<  sol.solveEquation(s) << endl;

    s = "x=x";
    cout <<  sol.solveEquation(s) << endl;

    s = "2x=x";
    cout <<  sol.solveEquation(s) << endl;

    return 0;
}
