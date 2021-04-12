/*
667. Beautiful Arrangement II
Medium

Given two integers n and k, you need to construct a list which contains n different positive integers ranging
from 1 to n and obeys the following requirement:

Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|]
has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3,
and the [1, 1] has exactly 1 distinct integer: 1.

Example 2:
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1]
has exactly 2 distinct integers: 1 and 2.

Note:
The n and k are in the range 1 <= k < n <= 10^4.
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
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int start = 1, end = k+1; start <= end; ++start, --end) {
            res.push_back(start);
            if (end > start)
                res.push_back(end);
        }
        for (int i = k+2; i <= n; ++i)
            res.push_back(i);

        return res;
    }
};

int main() {
    int n, k;

    // Output: [1, 2, 3]
    {
        Solution sol;
        n = 3, k = 1;
        auto res = sol.constructArray(n, k);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [1, 3, 2]
    {
        Solution sol;
        n = 3, k = 2;
        auto res = sol.constructArray(n, k);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    {
        Solution sol;
        n = 10, k = 6;
        auto res = sol.constructArray(n, k);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    {
        Solution sol;
        n = 30, k = 20;
        auto res = sol.constructArray(n, k);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
