/*
1545. Find Kth Bit in Nth Binary String
Medium

Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si-1 + "1" + reverse(invert(Si-1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x,
and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first 4 strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

Example 1:
Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001". The first bit is "0".

Example 2:
Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001". The 11th bit is "1".

Example 3:
Input: n = 1, k = 1
Output: "0"

Example 4:
Input: n = 2, k = 3
Output: "1"

Constraints:
1 <= n <= 20
1 <= k <= 2n - 1
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
    char findKthBit(int n, int k) {
        string s("0");
        for (int i = 2; i <= n; ++i) {
            string t;
            transform(s.begin(), s.end(), back_inserter(t), [] (char ch) {return ch == '0' ? '1' : '0';});
            reverse(t.begin(), t.end());
            s.push_back('1');
            s += t;
        }
        return s[k-1];
    }
};

int main() {
    Solution sol;
    int n, k;

    // Output: "0"
    n = 3, k = 1;
    cout << sol.findKthBit(n, k) << endl;

    // Output: "1"
    n = 4, k = 11;
    cout << sol.findKthBit(n, k) << endl;

    // Output: "0"
    n = 1, k = 1;
    cout << sol.findKthBit(n, k) << endl;

    // Output: "1"
    n = 2, k = 3;
    cout << sol.findKthBit(n, k) << endl;

    return 0;
}
