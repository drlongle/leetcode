/*
1416. Restore The Array
Hard

A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

Given the string s and the integer k. There can be multiple ways to restore the array.

Return the number of possible array that can be printed as a string s using the mentioned program.

The number of ways could be very large so return it modulo 10^9 + 7

Example 1:
Input: s = "1000", k = 10000
Output: 1
Explanation: The only possible array is [1000]

Example 2:
Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.

Example 3:
Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]

Example 4:
Input: s = "2020", k = 30
Output: 1
Explanation: The only possible array is [20,20]. [2020] is invalid because 2020 > 30. [2,020] is ivalid because 020 contains leading zeros.

Example 5:
Input: s = "1234567890", k = 90
Output: 34

Constraints:
1 <= s.length <= 10^5.
s consists of only digits and doesn't contain leading zeros.
1 <= k <= 10^9.
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
    static constexpr int MOD = 1000000007;

    long long get_num(const string&s, int i, int j) {
        long long res = 0;
        for (int index = i; index <= j; ++index)
            res = res*10 + s[index] - '0';
        return res;
    }
    
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0')
                continue;
            int prev = (i == 0 ? 1 : dp[i-1]);
            for (int j = i; j < n; ++j) {
                long long num = get_num(s, i, j);
                if (num > k)
                    break;
                dp[j] = (prev + dp[j]) % MOD;
            }
        }
        
        return dp[n-1];
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    // Output: 1
    s = "1000", k = 10000;
    cout << sol.numberOfArrays(s, k) << endl;

    // Output: 0
    s = "1000", k = 10;
    cout << sol.numberOfArrays(s, k) << endl;

    // Output: 8
    s = "1317", k = 2000;
    cout << sol.numberOfArrays(s, k) << endl;

    // Output: 1
    s = "2020", k = 30;
    cout << sol.numberOfArrays(s, k) << endl;

    // Output: 34
    s = "1234567890", k = 90;
    cout << sol.numberOfArrays(s, k) << endl;

    return 0;
}
