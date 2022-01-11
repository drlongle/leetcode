/*
1447. Simplified Fractions
Medium

Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive)
such that the denominator is less-than-or-equal-to n. The fractions can be in any order.

Example 1:
Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.

Example 2:
Input: n = 3
Output: ["1/2","1/3","2/3"]

Example 3:
Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".

Example 4:
Input: n = 1
Output: []

Constraints:
1 <= n <= 100
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int gcd(int a, int b) {
        if (a > b)
            swap(a, b);
        if (a == 0)
            return b;
        return gcd(b-a, a);
    }

    vector<string> res;
    vector<string> simplifiedFractions(int n) {
        res.clear();
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (gcd(j, i) == 1) {
                    ostringstream oss;
                    oss << j << '/' << i;
                    res.emplace_back(oss.str());
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> res;

    res = sol.simplifiedFractions(1);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    res = sol.simplifiedFractions(2);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    res = sol.simplifiedFractions(3);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    res = sol.simplifiedFractions(4);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    res = sol.simplifiedFractions(5);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    return 0;
}
