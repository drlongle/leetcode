/*
651. 4 Keys Keyboard
Medium

Imagine you have a special keyboard with the following keys:
A: Print one 'A' on the screen.
Ctrl-A: Select the whole screen.
Ctrl-C: Copy selection to buffer.
Ctrl-V: Print buffer on screen appending it after what has already been printed.
Given an integer n, return the maximum number of 'A' you can print on the screen with at most n presses on the keys.

Example 1:
Input: n = 3
Output: 3
Explanation: We can at most get 3 A's on screen by pressing the following key sequence:
A, A, A

Example 2:
Input: n = 7
Output: 9
Explanation: We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

Constraints:
1 <= n <= 50
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
    vector<int> dp;
    int maxA(int N) {
        dp.resize(N+1,0);
        return compute(N);
    }

    int compute(int N) {
        int& res = dp[N];
        if (res > 0)
            return res;
        res = N;
        for (int i = 1; i <= N-3; ++i) {
            int k = N - 2 - i;
            res = max(res, compute(i) * (k+1));
        }
        if (N > 3)
            res = max(res, 2*compute(N-3));
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
