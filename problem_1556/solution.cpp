/*
1556. Thousand Separator
Easy

Given an integer n, add a dot (".") as the thousands separator and return it in string format.

Example 1:
Input: n = 987
Output: "987"

Example 2:
Input: n = 1234
Output: "1.234"

Example 3:
Input: n = 123456789
Output: "123.456.789"

Example 4:
Input: n = 0
Output: "0"

Constraints:
0 <= n < 2^31
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
    string thousandSeparator(int n) {
        string s = to_string(n);
        int sz = s.size();
        ostringstream oss;
        for (int i = 0; i < sz; ++i) {
            oss << s[i];
            int diff = sz - i - 1;
            if (diff > 0 && diff % 3 == 0)
                oss << '.';
        }

        return oss.str();
    }
};

int main() {
    Solution sol;

    cout << sol.thousandSeparator(234) << endl;
    cout << sol.thousandSeparator(1234) << endl;
    cout << sol.thousandSeparator(12345678) << endl;
    cout << sol.thousandSeparator(123456789) << endl;
    return 0;
}
