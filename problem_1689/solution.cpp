/*
1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
Medium

A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros.
For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive
deci-binary numbers needed so that they sum up to n.

Example 1:
Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32

Example 2:
Input: n = "82734"
Output: 8

Example 3:
Input: n = "27346209830709182346"
Output: 9

Constraints:
1 <= n.length <= 10^5
n consists of only digits.
n does not contain any leading zeros and represents a positive integer.
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
    int minPartitions(string n) {
        return *max_element(begin(n), end(n)) - '0';
    }
};

int main() {
    Solution sol;
    string n;

    // Output: 3
    n = "32";
    cout << n << " -> " << sol.minPartitions(n) << endl;

    // Output: 8
    n = "82734";
    cout << n << " -> " << sol.minPartitions(n) << endl;

    // Output: 9
    n = "27346209830709182346";
    cout << n << " -> " << sol.minPartitions(n) << endl;

    return 0;
}
