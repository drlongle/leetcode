/*
1652. Defuse the Bomb
Easy

You have a bomb to defuse, and your time is running out! Your informer will provide you with a
circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

Example 1:
Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is
[7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.

Example 2:
Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]
Explanation: When k is zero, the numbers are replaced by 0.

Example 3:
Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again.
If k is negative, the sum is of the previous numbers.

Constraints:
n == code.length
1 <= n <= 100
1 <= code[i] <= 100
-(n - 1) <= k <= n - 1
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int get_index(int i, int n) {
        if (i < 0)
            return i + n;
        if (i < n)
            return i;
        return i - n;
    }

    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        int sum = 0;
        int sign = (k >= 0) ? 1 : -1;
        vector<int> res(n, 0);
        for (int i = 1; i <= abs(k); ++i) {
            int index = (sign == 1) ? i : n - i;
            sum += code[index];
        }

        for (int i = 0; i < n && k > 0; ++i) {
            res[i] = sum;
            sum -= code[(i+1) % n];
            sum += code[(i+k+1) % n];
        }

        for (int i = 0; i < n && k < 0; ++i) {
            res[get_index(i, n)] = sum;
            sum += code[i];
            sum -= code[get_index(n + i + k, n)];
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> code, res;
    int k;

    // Output: {12,10,16,13}
    code = {5,7,1,4}, k = 3;
    res = sol.decrypt(code, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {0,0,0,0}
    code = {1,2,3,4}, k = 0;
    res = sol.decrypt(code, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {12,5,6,13}
    code = {2,4,9,3}, k = -2;
    res = sol.decrypt(code, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Expected: {22,26,22,28,29,22,19,22,18,21,28,19}
    code = {10,5,7,7,3,2,10,3,6,9,1,6}, k = -4;
    res = sol.decrypt(code, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
