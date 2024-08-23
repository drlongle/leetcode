/*
592. Fraction Addition and Subtraction
Medium

Given a string expression representing an expression of fraction addition and
subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an
integer, change it to the format of a fraction that has a denominator 1. So in
this case, 2 should be converted to 2/1.

Example 1:
Input: expression = "-1/2+1/2"
Output: "0/1"

Example 2:
Input: expression = "-1/2+1/2+1/3"
Output: "1/3"

Example 3:
Input: expression = "1/3-1/2"
Output: "-1/6"

Constraints:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has the format ±numerator/denominator. If the
first input fraction or the output is positive, then '+' will be omitted. The
input only contains valid irreducible fractions, where the numerator and
denominator of each fraction will always be in the range [1, 10]. If the
denominator is 1, it means this fraction is actually an integer in a fraction
format defined above. The number of given fractions will be in the range [1,
10]. The numerator and denominator of the final result are guaranteed to be
valid and in the range of 32-bit int.
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

struct Fraction {
    int num, denom;
    Fraction &operator+=(const Fraction &rhs) {
        if (num == 0) {
            num = rhs.num;
            denom = rhs.denom;
        } else {
            num = num * rhs.denom + rhs.num * denom;
            denom *= rhs.denom;
            for (int n = 2; n <= min(abs(num), denom) / 2; ++n) {
                if (n > 2 && (n & 1) == 0)
                    continue;
                while (num % n == 0 && denom % n == 0) {
                    num /= n;
                    denom /= n;
                }
                if (num == 0 || abs(num) == 1 || denom == 1)
                    break;
            }
        }
        if (num == 0)
            denom = 1;
        return *this;
    }
    string to_string() const {
        return std::to_string(num) + '/' + std::to_string(denom);
    }
};

class Solution {
  public:
    enum class State { Sign, Num, Denom };
    string fractionAddition(string expression) {
        vector<Fraction> fracs;
        State state{State::Num};
        int num = 0, denom = 0;
        int sign = 1;
        size_t index;
        if (isdigit(expression[0])) {
            index = 0;
        } else {
            index = 1;
            sign = -1;
        }
        for (auto sz = expression.size(); index < sz; ++index) {
            char ch = expression[index];
            switch (state) {
            case State::Sign:
                sign = (ch == '-' ? -1 : 1);
                state = State::Num;
                break;
            case State::Num:
                if (isdigit(ch)) {
                    num = num * 10 + ch - '0';
                } else {
                    state = State::Denom;
                }
                break;
            case State::Denom:
                if (isdigit(ch)) {
                    denom = denom * 10 + ch - '0';
                } else {
                    --index;
                    state = State::Sign;
                    fracs.emplace_back(Fraction{sign * num, denom});
                    num = denom = 0;
                }
                break;
            }
        }
        fracs.emplace_back(Fraction{sign * num, denom});
        Fraction res{0, 0};
        for (auto &fr : fracs)
            res += fr;
        return res.to_string();
    }
};
int main() {
    Solution sol;

    // Output: "0/1"
    string expression = "-1/2+1/2";
    std::cout << "Output: " << sol.fractionAddition(expression) << std::endl;

    // Output: "1/3"
    expression = "-1/2+1/2+1/3";
    std::cout << "Output: " << sol.fractionAddition(expression) << std::endl;

    // Output: "-1/6"
    expression = "1/3-1/2";
    std::cout << "Output: " << sol.fractionAddition(expression) << std::endl;

    return 0;
}
