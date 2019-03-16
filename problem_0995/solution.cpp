/*
995. Minimum Number of K Consecutive Bit Flips
Difficulty: Hard

In an array A containing only 0s and 1s, a K-bit flip consists of choosing a
(contiguous) subarray of length K and simultaneously changing every 0 in
the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of K-bit flips required so that there is no 0 in the
array.  If it is not possible, return -1.

Example 1:
Input: A = [0,1,0], K = 1
Output: 2
Explanation: Flip A[0], then flip A[2].

Example 2:
Input: A = [1,1,0], K = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we can't make the
array become [1,1,1].

Example 3:
Input: A = [0,0,0,1,0,1,1,0], K = 3
Output: 3
Explanation:
Flip A[0],A[1],A[2]: A becomes [1,1,1,1,0,1,1,0]
Flip A[4],A[5],A[6]: A becomes [1,1,1,1,1,0,0,0]
Flip A[5],A[6],A[7]: A becomes [1,1,1,1,1,1,1,1]

Note:
1 <= A.length <= 30000
1 <= K <= A.length
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int count = 0, nsize = A.size();
        queue<int> flips;
        for (int i = 0; i < nsize; ++i) {
            while (flips.size() && flips.front()+K <= i)
                flips.pop();
            if ((A[i] + flips.size()) % 2 == 0) {
                if (i + K > nsize)
                    return -1;
                ++count;
                flips.emplace(i);
            }
        }
        return count;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> A;
    int K;

    // Expected: 2
    A = {0,1,0}, K = 1;

    // Expected: -1
    A = {1,1,0}, K = 2;

    // Expected: 3
    A = {0,0,0,1,0,1,1,0}, K = 3;

    //69 / 110 test cases passed.
    // Expected: -1
    A  = {0,1}, K = 2;

    //78 / 110 test cases passed.
    // Expected: -1
    A  = {0,1,1}, K = 2;

    //80 / 110 test cases passed.
    // Expected: 3
    A = {0,1,0,0,1,0};
    K = 4;

    //83 / 110 test cases passed.
    // Expected: 3
    A = {0,1,1,1,0,0};
    K = 3;

    //87 / 110 test cases passed.
    // Expcted: 3
    A = {0,1,0,0,1,0};
    K = 4;

    //90 / 110 test cases passed.
    // Expected: 4
    //A = {0,1,0,0,1,0,1};
    //K = 3;

    cout << "Result: " << sol.minKBitFlips(A, K) << endl;

    return 0;
}
