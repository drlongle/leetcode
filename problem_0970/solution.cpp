/*
970. Powerful Integers
Medium

Given three integers x, y, and bound, return a list of all the powerful integers that have a
value less than or equal to bound.

An integer is powerful if it can be represented as x^i + y^j for some integers i >= 0 and j >= 0.

You may return the answer in any order. In your answer, each value should occur at most once.

Example 1:
Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2

Example 2:
Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]

Constraints:
1 <= x, y <= 100
0 <= bound <= 10^6
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> X;
        for (int s = 1; s <= bound; s *= x) {
            X.insert(s);
            if (x == 1)
                break;
        }

        unordered_set<int> res;

        for (int s = 1; s <= bound; s *= y) {
            for (int n: X) {
                int t = n + s;
                if (t > bound)
                    break;
                res.insert(t);
            }
            if (y == 1)
                break;
        }

        return vector<int>(begin(res), end(res));
    }
};

int main() {
    Solution sol;
    int x, y, bound;
    vector<int> res;

    // Output: [2,3,4,5,7,9,10]
    x = 2, y = 3, bound = 10;
    res = sol.powerfulIntegers(x, y, bound);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: [2,4,6,8,10,14]
    x = 3, y = 5, bound = 15;
    res = sol.powerfulIntegers(x, y, bound);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    x = 2, y = 1, bound = 10;
    res = sol.powerfulIntegers(x, y, bound);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
