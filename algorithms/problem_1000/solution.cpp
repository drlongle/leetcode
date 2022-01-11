/*
1000. Minimum Cost to Merge Stones
Difficulty: Hard

There are N piles of stones arranged in a row. The i-th pile has stones[i] stones.
A move consists of merging exactly K consecutive piles into one pile, and the
cost of this move is equal to the total number of stones in these K piles. Find
the minimum cost to merge all piles of stones into one pile. If it is impossible,
return -1.

Example 1:
Input: stones = [3,2,4,1], K = 2
Output: 20
Explanation:
We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.

Example 2:
Input: stones = [3,2,4,1], K = 3
Output: -1
Explanation: After any merge operation, there are 2 piles left,
and we can't merge anymore. So the task is impossible.

Example 3:
Input: stones = [3,5,1,2,6], K = 3
Output: 25
Explanation:
We start with [3, 5, 1, 2, 6].
We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
We merge [3, 8, 6] for a cost of 17, and we are left with [17].
The total cost was 25, and this is the minimum possible.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
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

/*
We keep merging K piles of stones until there is only one pile. For the last step,
stones[i .. j] are divided into K piles, and we merge them into one pile, which costs
sum(nums[i .. j]) + cost to make stones[i .. j] form K piles.

The problem get the minimum cost to make stones[i .. j] form 1 pile equals to
	the minimum cost to make stones[i .. j] form K piles
	+ sum(nums[i .. j])

The subproblem the minimum cost to make stones[i .. j] form K piles equals to
	the minimum cost to make stones[i .. k] form K - 1 piles
	+ the minimum cost to make stones[k + 1 .. j] form 1 pile 
	+ sum(nums[i .. j])
*/

class Solution {
public:
    int merge_helper(list<int>& stones, int left, int right, int k, int K) {
        if (left == right)
            return (k == 1) ? 0 : -1;
        int best = -1;
        int sum_lr = sum[right] - ((left > 0) ? sum[left-1] : 0);
        int nums = right - left + 1;
        if (nums == K)
            return sum_lr;

        // Don't add the cost for adding subsum
        if (nums == k)
            return 0;
        if (k <= 0)
            return -1;
        if (k == 1) {
            if (K > 2 && nums % (K-1) != 1)
                return -1;
            return (nums < K) ? -1 : merge_helper(stones, left, right, K, K);
        }

        if (memo[k][left][right] != 0)
            return memo[k][left][right];

        for (int i = left; i < right; ++i) {
            int x = merge_helper(stones, left, i, k-1, K);
            int y = merge_helper(stones, i+1, right, 1, K);
            if (x >= 0 && y >= 0 && (best < 0 || (best >= 0 && best > x + y)))
                best = x + y;
        }

        int res = (best < 0) ? -1 : (best + ((k == K) ? sum_lr : 0));
        memo[k][left][right] = res;

        return res;

    }
    
    int mergeStones(vector<int>& stones, int K) {
        list<int> s{begin(stones), end(stones)};
        ssize = static_cast<int>(stones.size());
        if (K > 2 && ssize % (K-1) != 1)
            return -1;
        if (ssize == 1)
            return 0;

        memo.resize(K+1, vector<vector<int>>(ssize, vector<int>(ssize, 0)));
        sum.resize(ssize);
        partial_sum(begin(stones), end(stones), begin(sum));

        return merge_helper(s, 0, ssize-1, K, K);
    }

    vector<vector<vector<int>>> memo;
    vector<int> sum;
    int ssize;
};

int main() {
    Solution sol;
    vector<int> stones;
    int K;

    // Expected: 15
    stones = {6, 9}, K = 2;

    // Expected: 13
    stones = {1, 4, 3}, K = 2;

    // Expected: 20
    stones = {3,2,4,1}, K = 2;

    // Expected: 15
    //stones = {5,4,1}, K = 2;

    // 23 / 83 test cases passed.
    // Expected: -1
    //stones = {3,2,4,1}, K = 3;

    // 25 / 83 test cases passed
    // Expected: 25
    stones = {3,5,1,2,6}, K = 3;

    //stones = {69,39,79,78,16,6,36,97,79,27,14,31,4}, K = 2;

    // 47 / 83 test cases passed
    // Expected: 138
    //stones = {2,5,6,8,4,3,8,7,1}, K = 2;

    // 49 / 83 test cases passed.
    // Expected: 1930
    //stones = {26,88,89,24,74,73,69,2,59,58,89,75,94}, K = 3;


    // 51 / 83 test cases passed
    // Expected: 25
    //stones = {3,5,1,2,6}, K = 3;

    // 61 / 83 test cases passed.
    // Expected: 40
    //stones = {6,4,4,6};
    //K = 2;

    // 71 / 83 test cases passed.
    //stones = {1}, K = 2;

    //stones = {1,2}, K = 2;

    cout << "Result: " << sol.mergeStones(stones, K) << endl;

    return 0;
}

