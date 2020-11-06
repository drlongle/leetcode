/*
910. Smallest Range II
Medium

Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and
add x to A[i] (only once).

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
Output: 3
Explanation: B = [4,6,3]

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

/*
 Iterate for all i in range(0, sz-1)
 - Divide A into two segments [A[0]..A[i]] and [A[i+1]..A[sz-1]].
 - Add K to each element in the first segment and subtract K from each element in the second segment.
 - Find the maximum different of these two new segments.
*/

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(begin(A), end(A));
        int res = A.back() - A[0];
        auto it = unique(A.begin(), A.end());
        A.erase(it, A.end());
        int sz = A.size();
        for (int i = 0; i < sz-1; ++i) {
            int lo = numeric_limits<int>::max(), hi = numeric_limits<int>::min();
            hi = max(hi, A[i]+ K);
            lo = min(lo, A[0] + K);
            hi = max(hi, A.back() - K);
            lo = min(lo, A[i+1] - K);
            res = min(res, abs(hi-lo));
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> A;
    int K;

    // Output: 0
    A = {1}, K = 0;
    cout << sol.smallestRangeII(A, K) << endl;

    // Output: 6
    A = {0,10}, K = 2;
    cout << sol.smallestRangeII(A, K) << endl;

    // Output: 3
    A = {1,3,6}, K = 3;
    cout << sol.smallestRangeII(A, K) << endl;

    // Output: 3
    A = {2,7,2}, K = 1;
    cout << sol.smallestRangeII(A, K) << endl;

    // Output: 1
    A = {7,8,8}, K = 5;
    cout << sol.smallestRangeII(A, K) << endl;

    // Output: 7
    A = {3,4,7,0}, K = 5;
    cout << sol.smallestRangeII(A, K) << endl;

    // Output: 2
    A = {3,1,10}, K = 4;
    cout << sol.smallestRangeII(A, K) << endl;

    // Output: 5
    A = {7,8,8,5,2}, K = 4;
    cout << sol.smallestRangeII(A, K) << endl;

    // Output: 7974
    A = {506,4763,8681,4243,4040,8587,9235,442,1865,2820}, K = 5899;
    cout << sol.smallestRangeII(A, K) << endl;

    // Output: 8870
    A = {8038,9111,5458,8483,5052,9161,8368,2094,8366,9164,53,7222,9284,5059,4375,2667,2243,5329,3111,5678,5958,815,
         6841,1377,2752,8569,1483,9191,4675,6230,1169,9833,5366,502,1591,5113,2706,8515,3710,7272,1596,5114,3620,2911,
         8378,8012,4586,9610,8361,1646,2025,1323,5176,1832,7321,1900,1926,5518,8801,679,3368,2086,7486,575,9221,2993,
         421,1202,1845,9767,4533,1505,820,967,2811,5603,574,6920,5493,9490,9303,4648,281,2947,4117,2848,7395,930,1023,
         1439,8045,5161,2315,5705,7596,5854,1835,6591,2553,8628};
    K = 4643;
    cout << sol.smallestRangeII(A, K) << endl;

    return 0;
}
