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

class Solution {
public:
    int merge_helper(list<int>& stones, int K) {
        int ssize = static_cast<int>(stones.size());
        if (ssize == 1)
            return *(stones.begin());
        if (ssize < K)
            return -1;

        int sum = 0;
        queue<int> elems;
        auto it = stones.begin();
        for (int i = 0; i < K; ++i) {
            sum += *it;
            elems.push(*it);
            it = stones.erase(it);
        }

        int res = numeric_limits<int>::max();
        while (it != stones.end()) {
            sum = sum + *it - (static_cast<int>(elems.size()) == K  ? elems.front() : 0);
            auto it2 = stones.insert(it, sum);
            res = min(res, merge_helper(stones, K));
            stones.erase(it2);
            elems.push(*it);
            elems.pop();
            it = stones.erase(it);
        }

        while (!elems.empty()) {
            stones.push_back(elems.front());
            elems.pop();
        }

        return res;
    }

    int mergeStones(vector<int>& stones, int K) {
        list<int> s{begin(stones), end(stones)};

        return merge_helper(s, K);
    }
};

int main() {
    Solution sol;
    vector<int> stones;
    int K;

    // Expected: 15
    stones = {6, 9}, K = 2;

    // Expected: 13?
    stones = {1, 4, 3}, K = 2;

    // Expected: 20
    //stones = {3,2,4,1}, K = 2;

    // Expected: -1
    //stones = {3,2,4,1}, K = 3;

    // 25 / 83 test cases passed
    // Expected: 25
    //stones = {3,5,1,2,6}, K = 3;

    //stones = {69,39,79,78,16,6,36,97,79,27,14,31,4}, K = 2;

    // 47 / 83 test cases passed
    // Expected: 138
    //stones = {2,5,6,8,4,3,8,7,1}, K = 2;

    // 49 / 83 test cases passed.
    // Expected: 1930
    //stones = {26,88,89,24,74,73,69,2,59,58,89,75,94}, K = 3;
    
    // 61 / 83 test cases passed.
    // Expected: 40
    //stones = {6,4,4,6};
    //K = 2;

    cout << "Result: " << sol.mergeStones(stones, K) << endl;

    return 0;
}
