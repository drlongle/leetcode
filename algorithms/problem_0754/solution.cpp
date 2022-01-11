/*
754. Reach a Number
Medium

You are standing at position 0 on an infinite number line. There is a goal at position target.

On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

Return the minimum number of steps required to reach the destination.

Example 1:
Input: target = 3
Output: 2
Explanation:
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.

Example 2:
Input: target = 2
Output: 3
Explanation:
On the first move we step from 0 to 1.
On the second move we step from 1 to -1.
On the third move we step from -1 to 2.
Note:
target will be a non-zero integer in the range [-10^9, 10^9].
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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
    bool reach(long long target, long long step) {
        if (step == 0)
            return false;
        long long sum = step * (step + 1) / 2;
        if (sum < target)
            return false;
        if (sum == target)
            return true;
        return reach(abs(target - step), step - 1);
    }

    int reachNumber(int target) {
        for (long long i = 1; i <= 1000000000; ++i)
            if (reach(abs(target), i))
                return i;

        return -1;
    }
};

int main() {
    Solution sol;
    int target;

    // Output: 3: [1, -1, 2]
    target = 2;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    // Output: 2: [1, 3]
    target = 3;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    // Output: 3: [-1, 1, 4]
    target = 4;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    // Output: 5: [1, -1, -4, 0, 5]
    target = 5;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    // Output: 3: [1, 3, 6]
    target = 6;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    // Output: 5: [-1, 1, -2, 2, 7]
    target = 7;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    // Output: 4
    target = 10;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    // Output: 15
    target = 100;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    // Output: 47
    target = 1000;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    target = 1000000000;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    target = -1;
    cout << target << " -> " << sol.reachNumber(target) << endl;

    return 0;
}
