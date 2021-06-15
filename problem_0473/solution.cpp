/*
473. Matchsticks to Square
Medium

You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick.
You want to use all the matchsticks to make one square. You should not break any stick,
but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

Example 1:
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Example 2:
Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.

Constraints:
1 <= matchsticks.length <= 15
0 <= matchsticks[i] <= 10^9
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

class Solution {
public:
    using ll = long long;
    using ARRAY = array<ll, 4>;
    ll sum = 0;
    unordered_set<ll> visited;

    bool compute(const vector<int>& sticks, ARRAY sides, int level) {
        ll sum = 0, key = level;
        sort(begin(sides), end(sides));
        for (auto side: sides) {
            sum += side;
            key = key * 1001 + side;
        }
        if (sum == 0) {
            return true;
        }
        if (!visited.insert(key).second)
            return false;

        int num = sticks[level];
        for (int j = 0; j < 4; ++j) {
            if (j > 0 && sides[j] == sides[j-1])
                continue;
            sides[j] -= num;
            if (sides[j] >= 0 && compute(sticks, sides, level + 1))
                return true;
            sides[j] += num;
        }

        return false;
    }

    bool makesquare(vector<int>& sticks) {
        for (auto stick: sticks)
            sum += stick;
        if (sum % 4 != 0)
            return false;
        int elem = sum / 4;
        ARRAY sides{elem, elem, elem, elem};
        return compute(sticks, sides, 0);
    }
};

int main() {
    vector<int> matchsticks;

    // Output: true
    {
        Solution sol;
        matchsticks = {1,1,2,2,2};
        cout << boolalpha << sol.makesquare(matchsticks) << endl;
    }

    // Output: false
    {
        Solution sol;
        matchsticks = {3, 3, 3, 3, 4};
        cout << boolalpha << sol.makesquare(matchsticks) << endl;
    }

    // Output: true
    {
        Solution sol;
        matchsticks = {5,5,5,5,4,4,4,4,3,3,3,3};
        cout << boolalpha << sol.makesquare(matchsticks) << endl;
    }

    // true
    {
        Solution sol;
        matchsticks = {7,1,13,6,19,18,12,3,15,4,20,11,2,15,14};
        cout << boolalpha << sol.makesquare(matchsticks) << endl;
    }

    // false
    {
        Solution sol;
        matchsticks = {1569462,2402351,9513693,2220521,7730020,7930469,1040519,5767807,876240,350944,4674663,4809943,8379742,3517287,8034755};
        cout << boolalpha << sol.makesquare(matchsticks) << endl;
    }

    // false
    {
        Solution sol;
        matchsticks = {6122053,1031956,460065,3996684,3891947,1839190,6127621,8855952,8835594,3425930,4189081,7596722,876208,7952011,9676846};
        cout << boolalpha << sol.makesquare(matchsticks) << endl;
    }

    // false
    {
        Solution sol;
        matchsticks = {5,5,5,5,16,4,4,4,4,4,3,3,3,3,4};
        cout << boolalpha << sol.makesquare(matchsticks) << endl;
    }

    return 0;
}
