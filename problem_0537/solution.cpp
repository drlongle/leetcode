/*
537. Complex Number Multiplication
Medium

A complex number can be represented as a string on the form "real+imaginaryi" where:

real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i^2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.


Example 1:
Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:
Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

Constraints:
num1 and num2 are valid complex numbers.
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
    string complexNumberMultiply(string num1, string num2) {
        auto it = num1.find('+');
        auto r1 = stoi(num1.substr(0, it));
        auto i1 = stoi(num1.substr(it + 1, num1.size() - it - 2));

        it = num2.find('+');
        auto r2 = stoi(num2.substr(0, it));
        auto i2 = stoi(num2.substr(it + 1, num2.size() - it - 2));

        int r = r1 * r2 - i1 * i2;
        int i = r1 * i2 + r2 * i1;
        ostringstream oss;
        oss << r << '+' << i << 'i';

        return oss.str();
    }
};

int main() {
    Solution sol;
    string num1, num2;

    // Output: "0+2i"
    num1 = "1+1i", num2 = "1+1i";
    cout << sol.complexNumberMultiply(num1, num2) << endl;

    // Output: "0+-2i"
    num1 = "1+-1i", num2 = "1+-1i";
    cout << sol.complexNumberMultiply(num1, num2) << endl;

    num1 = "78+-76i", num2 = "-86+72i";
    cout << sol.complexNumberMultiply(num1, num2) << endl;

    return 0;
}
