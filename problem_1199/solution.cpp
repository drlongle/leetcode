/*
1199. Minimum Time to Build Blocks
Hard

You are given a list of blocks, where blocks[i] = t means that the i-th block needs t
units of time to be built. A block can only be built by exactly one worker.

A worker can either split into two workers (number of workers increases by one) or build a block
then go home. Both decisions cost some time.

The time cost of spliting one worker into two workers is given as an integer split. Note that if
two workers split at the same time, they split in parallel so the cost would be split.

Output the minimum time needed to build all blocks. Initially, there is only one worker. 

Example 1:
Input: blocks = [1], split = 1
Output: 1
Explanation: We use 1 worker to build 1 block in 1 time unit.

Example 2:
Input: blocks = [1,2], split = 5
Output: 7
Explanation: We split the worker into 2 workers in 5 time units then assign each of them to a block so the cost is 5 + max(1, 2) = 7.

Example 3:
Input: blocks = [1,2,3], split = 1
Output: 4
Explanation: Split 1 worker into 2, then assign the first worker to the last block and split the
second worker into 2. Then, use the two unassigned workers to build the first two blocks.
The cost is 1 + max(3, 1 + max(1, 2)) = 4.
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

    int build(vector<int> blocks, int index, int workers, int split) {
        if (workers >= index + 1)
            return blocks[index];
        auto it = dp.find({index, workers});
        if (it != end(dp))
            return it->second;

        int res = split + build(blocks, index, 2*workers, split);
        if (workers > 1)
            res = min(res, max(blocks[index], build(blocks, index-1, workers-1, split)));
        dp[{index, workers}] = res;
        return res;
    }
    
    int minBuildTime(vector<int>& blocks, int split) {
        dp.clear();
        sort(begin(blocks), end(blocks));
        return build(blocks, blocks.size()-1, 1, split);
    }
    map<pair<int, int>, int> dp;
};

int main() {
    Solution sol;
    vector<int> blocks;
    int split;

    // Output: 1
    blocks = {1}, split = 1;

    // Output: 7
    blocks = {1,2}, split = 5;

    // Output: 4
    blocks = {1,2,3}, split = 1;

    // Output: 5
    //blocks = {1,2,3,4}, split = 1;
    
    // Output: 6
    //blocks = {1,2,3,4,5}, split = 1;

    // Output: 15
    //blocks = {1,3,5,7,11}, split = 3;
    
    // Output: 23
    //blocks = {1,3,5,7,20}, split = 3;

    // Output: 201
    //blocks = {1,1,1,1}, split = 100;

    // Output: 95051
    blocks = {94961,39414,41263,7809,41473}, split = 90;
    
    cout << "Result: " << sol.minBuildTime(blocks, split) << endl;

    
    return 0;
}
