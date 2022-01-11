/*
1881. Maximum Value after Insertion
Medium

You are given a very large integer n, represented as a string, and an integer digit x. The digits
in n and the digit x are in the inclusive range [1, 9], and n may represent a negative number.

You want to maximize n's numerical value by inserting x anywhere in the decimal representation of n.
You cannot insert x to the left of the negative sign.

For example, if n = 73 and x = 6, it would be best to insert it between 7 and 3, making n = 763.
If n = -55 and x = 2, it would be best to insert it before the first 5, making n = -255.
Return a string representing the maximum value of n after the insertion.

Example 1:
Input: n = "99", x = 9
Output: "999"
Explanation: The result is the same regardless of where you insert 9.

Example 2:
Input: n = "-13", x = 2
Output: "-123"
Explanation: You can make n one of {-213, -123, -132}, and the largest of those three is -123.

Constraints:
1 <= n.length <= 10^5
1 <= x <= 9
The digits in n are in the range [1, 9].
n is a valid representation of an integer.
In the case of a negative n, it will begin with '-'.
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
    string maxValue(string n, int x) {
        char c = '0' + x;
        int sz = n.size();
        if (n[0] == '-') {
            for (int i = 1; i < sz; ++i) {
                if (c < n[i]) {
                    n.insert(i, 1, c);
                    return n;
                }
            }
            n.push_back(c);
        } else {
            for (int i = 0; i < sz; ++i) {
                if (c > n[i]) {
                    n.insert(i, 1, c);
                    return n;
                }
            }
            n.push_back(c);
        }

        return n;
    }
};

int main() {
    Solution sol;
    string n;
    int x;

    // Output: "999"
    n = "99", x = 9;
    cout << sol.maxValue(n, x) << endl;

    n = "246", x = 5;
    cout << sol.maxValue(n, x) << endl;

    n = "426", x = 3;
    cout << sol.maxValue(n, x) << endl;

    // Output: "-123"
    n = "-13", x = 2;
    cout << sol.maxValue(n, x) << endl;

    return 0;
}
