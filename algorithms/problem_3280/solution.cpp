/*
3280. Convert Date to Binary
Easy

You are given a string date representing a Gregorian calendar date in the
yyyy-mm-dd format.

date can be written in its binary representation obtained by converting year,
month, and day to their binary representations without any leading zeroes and
writing them down in year-month-day format.

Return the binary representation of date.

Example 1:
Input: date = "2080-02-29"
Output: "100000100000-10-11101"
Explanation:
100000100000, 10, and 11101 are the binary representations of 2080, 02, and 29
respectively.

Example 2:
Input: date = "1900-01-01"
Output: "11101101100-1-1"

Explanation:
11101101100, 1, and 1 are the binary representations of 1900, 1, and 1
respectively.


Constraints:
date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits.
The input is generated such that date represents a valid Gregorian calendar date
between Jan 1st, 1900 and Dec 31st, 2100 (both inclusive).
*/

#include <algorithm>
#include <atomic>
#include <bit>
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

class Solution {
  public:
    string toBinary(int n) {
        string s;
        while (n) {
            s += ((n & 1) ? '1' : '0');
            n /= 2;
        }
        std::ranges::reverse(s);
        return s;
    }

    string convertDateToBinary(string date) {
        auto year = stoi(date.substr(0, 4));
        auto month = stoi(date.substr(5, 2));
        auto day = stoi(date.substr(8));

        return toBinary(year) + '-' + toBinary(month) + '-' + toBinary(day);
    }
};

int main() {
    Solution sol;
    string date;

    date = "2080-02-29";
    cout << sol.convertDateToBinary(date) << endl;
    return 0;
}
