/*
1415. The k-th Lexicographical String of All Happy Strings of Length n
Medium

A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

Example 1:
Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

Example 2:
Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.

Example 3:
Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"

Example 4:
Input: n = 2, k = 7
Output: ""

Example 5:
Input: n = 10, k = 100
Output: "abacbabacb"

Constraints:
1 <= n <= 10
1 <= k <= 100
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
    string getHappyString(int n, int k) {
        --k;
        vector<int> offsets(n, 0);
        string res(n, 'a');
        int index = n;
        for (int i = n - 1; i >= 0 && k > 0; --i, --index) {
            if (i == 0) {
                if (k >= 3)
                    return "";
                offsets[i] = k;
                k /= 3;
            } else {
                offsets[i] = k % 2;
                k /= 2;
            }
        }
        for (int i = 0; i < index; ++i) {
            if (i % 2 == 0)
                res[i] = 'a';
            else
                res[i] = 'b';
        }
        for (int i = index; i < n; ++i) {
            if (i == 0)
                res[0] += offsets[0];
            else {
                if (res[i-1] == 'a') {
                    if (offsets[i] == 0)
                        res[i] = 'b';
                    else
                        res[i] = 'c';
                } else if (res[i-1] == 'b') {
                    if (offsets[i] == 0)
                        res[i] = 'a';
                    else
                        res[i] = 'c';
                } else {
                    res[i] += offsets[i];
                }

            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    int n, k;

    // Output: "c"
    n = 1, k = 3;
    cout << sol.getHappyString(n, k) << endl;

    // Output: ""
    n = 1, k = 4;
    cout << sol.getHappyString(n, k) << endl;
    
    // Output: "cab"
    n = 3, k = 9;
    cout << sol.getHappyString(n, k) << endl;
    
    // Output: ""
    n = 2, k = 7;
    cout << sol.getHappyString(n, k) << endl;
    
    // Output: "abacbabacb"
    n = 10, k = 100;
    cout << sol.getHappyString(n, k) << endl;

    // Expected: "ababcbc"
    n = 7, k = 8;
    cout << sol.getHappyString(n, k) << endl;
    
    return 0;
}
