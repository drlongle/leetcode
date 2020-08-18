/*
967. Numbers With Same Consecutive Differences
Medium

Return all non-negative integers of length N such that the absolute difference between every
two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself.
For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

Example 1:
Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

Example 2:
Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

Note:
1 <= N <= 9
0 <= K <= 9
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

using namespace std;

class Solution {
public:
    vector<int> res;

    void dfs(int curr, int level, int N, int K) {
        if (level == N) {
            res.emplace_back(curr);
            return;
        }
        int last_digit = curr % 10;
        if (K == 0) {
            dfs(curr * 10 + last_digit, level + 1, N, K);
        } else {
            if (last_digit - K >= 0)
                dfs(curr * 10 + last_digit - K, level + 1, N, K);
            if (last_digit + K <= 9)
                dfs(curr * 10 + last_digit + K, level + 1, N, K);
        }
    }

    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            res.resize(10);
            iota(begin(res), end(res), 0);
            return res;
        }
        for (int i = 1; i <= 9; ++i)
            dfs(i, 1, N, K);
        return res;
    }
};

int main() {
    int N, K;

    {
        Solution sol;
        N = 1, K = 7;
        auto res = sol.numsSameConsecDiff(N, K);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [181,292,707,818,929]
    {
        Solution sol;
        N = 3, K = 7;
        auto res = sol.numsSameConsecDiff(N, K);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
    {
        Solution sol;
        N = 2, K = 1;
        auto res = sol.numsSameConsecDiff(N, K);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [11,22,33,44,55,66,77,88,99]
    {
        Solution sol;
        N = 2, K = 0;
        auto res = sol.numsSameConsecDiff(N, K);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
