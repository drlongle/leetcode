/*
1015. Smallest Integer Divisible by K
Medium

Given a positive integer K, you need to find the length of the smallest positive integer N such that N is
divisible by K, and N only contains the digit 1.

Return the length of N. If there is no such N, return -1.

Note: N may not fit in a 64-bit signed integer.

Example 1:
Input: K = 1
Output: 1
Explanation: The smallest answer is N = 1, which has length 1.

Example 2:
Input: K = 2
Output: -1
Explanation: There is no such positive integer N divisible by 2.

Example 3:
Input: K = 3
Output: 3
Explanation: The smallest answer is N = 111, which has length 3.

Constraints:
1 <= K <= 10^5
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
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0)
            return -1;
        int mod = 1, pow = 1, len = 1;
        for (int i = 0; i < 50000; ++i) {
            mod %= K;
            if (mod == 0)
                return len;
            ++len;
            pow = (pow * 10) % K;
            mod += pow;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int K;

    K = 1;
    cout << sol.smallestRepunitDivByK(K) << endl;

    K = 2;
    cout << sol.smallestRepunitDivByK(K) << endl;

    K = 3   ;
    cout << sol.smallestRepunitDivByK(K) << endl;

    return 0;
}
