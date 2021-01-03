/*
526. Beautiful Arrangement
Medium

Suppose you have n integers from 1 to n. We define a beautiful arrangement as an array
that is constructed by these n numbers successfully if one of the following is true for
the ith position (1 <= i <= n) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.

Given an integer n, return the number of the beautiful arrangements that you can construct.

Example 1:
Input: n = 2
Output: 2
Explanation:
The first beautiful arrangement is [1, 2]:
Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
The second beautiful arrangement is [2, 1]:
Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.

Example 2:
Input: n = 1
Output: 1

Constraints:
1 <= n <= 15
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
    vector<vector<int>> candidates {
            {},
            {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
            {1,2,4,6,8,10,12,14},
            {1,3,6,9,12,15},
            {1,2,4,8,12},
            {1,5,10,15},
            {1,2,3,6,12},
            {1,7,14},
            {1,2,4,8},
            {1,3,9},
            {1,2,5,10},
            {1,11},
            {1,2,3,4,6,12},
            {1,13},
            {1,2,7,14},
            {1,3,5,15}
    };

    vector<bool> taken;
    int n;

    Solution(): taken(16, false) {}

    int DFS(int index) {
        if (index == n+1)
            return 1;
        int cnt = 0;
        for (int i: candidates[index]) {
            if (!taken[i] && i <= n) {
                taken[i] = true;
                cnt += DFS(index+1);
                taken[i] = false;
            }
        }
        return cnt;
    }

    int countArrangement(int n) {
        this->n = n;
        return DFS(1);
    }
};

int main() {
    Solution sol;
    int n;

    n = 2;
    cout << n << " -> " << sol.countArrangement(n) << endl;

    n = 1;
    cout << n << " -> " << sol.countArrangement(n) << endl;

    n = 3;
    cout << n << " -> " << sol.countArrangement(n) << endl;

    n = 4;
    cout << n << " -> " << sol.countArrangement(n) << endl;

    return 0;
}
