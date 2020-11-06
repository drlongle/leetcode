/*
908. Smallest Range I
Easy

Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.

Example 1:
Input: A = [1], K = 0
Output: 0
Explanation: B = [1]

Example 2:
Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]

Example 3:
Input: A = [1,3,6], K = 3
Output: 0
Explanation: B = [3,3,3] or B = [4,4,4]

Note:
1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
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
    int smallestRangeI(vector<int>& A, int K) {
        int mx = *max_element(A.begin(), A.end());
        int mn = *min_element(A.begin(), A.end());
        int avg = (mx + mn) / 2;
        int res = mx - mn;
        int lo = mx, hi = mn;

        for (int n: A) {
            if (n <= avg) {
                lo = min(lo, n+K);
            } else
                hi = max(hi, n-K);
        }
        return min(res, max(hi - lo, 0));
    }
};

int main() {
    Solution sol;
    vector<int> A;
    int K;

    // Output: 0
    A = {1}, K = 0;
    cout << sol.smallestRangeI(A, K) << endl;

    // Output: 6
    A = {0,10}, K = 2;
    cout << sol.smallestRangeI(A, K) << endl;

    // Output: 0
    A = {1,3,6}, K = 3;
    cout << sol.smallestRangeI(A, K) << endl;

    A = {3,1,10}, K = 4;
    cout << sol.smallestRangeI(A, K) << endl;

    return 0;
}
