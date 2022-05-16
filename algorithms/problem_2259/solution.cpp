/*
2259. Remove Digit From Number to Maximize Result
Easy

You are given a string number representing a positive integer and a character
digit.

Return the resulting string after removing exactly one occurrence of digit from
number such that the value of the resulting string in decimal form is maximized.
The test cases are generated such that digit occurs at least once in number.

Example 1:
Input: number = "123", digit = "3"
Output: "12"
Explanation: There is only one '3' in "123". After removing '3', the result is
"12".

Example 2:
Input: number = "1231", digit = "1"
Output: "231"
Explanation: We can remove the first '1' to get "231" or remove the second '1'
to get "123". Since 231 > 123, we return "231".

Example 3:
Input: number = "551", digit = "5"
Output: "51"
Explanation: We can remove either the first or second '5' from "551".
Both result in the string "51".

Constraints:
2 <= number.length <= 100
number consists of digits from '1' to '9'.
digit is a digit from '1' to '9'.
digit occurs at least once in number.
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

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    string removeDigit(string number, char digit) {
        string res;
        auto pos = 0;
        while (true) {
            pos = number.find(digit, pos);
            if (pos == string::npos)
                break;
            string cand = number;
            cand.erase(pos, 1);
            if (cand > res)
                res = cand;
            ++pos;
        }
        return res;
    }
};

int main() {
    Solution sol;

    cout << sol.removeDigit("123", '3') << endl;
    cout << sol.removeDigit("1231", '1') << endl;
    cout << sol.removeDigit("551", '5') << endl;

    return 0;
}
