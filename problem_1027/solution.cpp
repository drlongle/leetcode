/*
1027. Longest Arithmetic Subsequence
Medium

Given an array A of integers, return the length of the longest arithmetic subsequence in A.

Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with
0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic
if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

Example 1:
Input: A = [3,6,9,12]
Output: 4
Explanation:
The whole array is an arithmetic sequence with steps of length = 3.

Example 2:
Input: A = [9,4,7,2,10]
Output: 3
Explanation:
The longest arithmetic subsequence is [4,7,10].

Example 3:
Input: A = [20,1,15,3,10,5,8]
Output: 4
Explanation:
The longest arithmetic subsequence is [20,15,10,5].

Constraints:
2 <= A.length <= 1000
0 <= A[i] <= 500
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), res = 1;
        vector<vector<int>> dp(n, vector(1001, 0));

        for (int i = 0; i < n; ++i){
            auto& m = dp[i];
            for(int j = 0; j < i;++j){
                int d = A[i]- A[j] + 500;
                m[d] = max(m[d], 1+ max(1, dp[j][d]));
                res = max(res, m[d]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
