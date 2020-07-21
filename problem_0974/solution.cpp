/*
974. Subarray Sums Divisible by K
Medium

Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

Example 1:
Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Note:
1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000
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

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum = 0, res = 0;
        unordered_map<int, int> cnt;
        for (int a: A) {
            sum = (sum + a) % K;
            if (sum < 0)
                sum += K;
            res += cnt[sum];
            ++cnt[sum];
            if (sum == 0)
                ++res;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> A;
    int K;

    // Output: 7
    A = {4,5,0,-2,-3,1}, K = 5;
    cout << sol.subarraysDivByK(A, K) << endl;

    return 0;
}
