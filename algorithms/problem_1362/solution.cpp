/*
1362. Closest Divisors
Medium

Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.

Return the two integers in any order.

Example 1:
Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.

Example 2:
Input: num = 123
Output: [5,25]

Example 3:
Input: num = 999
Output: [40,25]

Constraints:
1 <= num <= 10^9
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    void explore(int num) {
        for (int n = ceil(sqrt(num)); n > 1; --n) {
            int d = num / n;
            if (n * d == num) {
                if (res.empty() || abs(res[1] - res[0]) > abs(n - d))
                    res = {n, d};
            }
        }
    }
    
    vector<int> closestDivisors(int num) {
        explore(num+1);
        explore(num+2);
        return res;
    }
    vector<int> res;
};

int main() {
    Solution sol;
    return 0;
}
