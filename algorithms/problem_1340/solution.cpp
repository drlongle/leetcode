/*
1340. Jump Game V
Hard

Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and 0 < x <= d.
i - x where: i - x >= 0 and 0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.

Example 1:
Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.

Example 2:
Input: arr = [3,3,3,3,3], d = 3
Output: 1
Explanation: You can start at any index. You always cannot jump to any index.

Example 3:
Input: arr = [7,6,5,4,3,2,1], d = 1
Output: 7
Explanation: Start at index 0. You can visit all the indicies. 

Example 4:
Input: arr = [7,1,7,1,7,1], d = 2
Output: 2

Example 5:
Input: arr = [66], d = 1
Output: 1

Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 10^5
1 <= d <= arr.length
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

    int res, sz;
    multimap<int, int, greater<int>> lookup;
    vector<vector<int>> next;
    vector<int> dp;
    
    void process(vector<int>& arr, int i, int offset) {
        int j = i + offset;
        if (j >= 0 && j < sz) {
            auto it = lookup.lower_bound(arr[j]);
            while (it != lookup.end() && it->second != j)
                ++it;
            if (it != lookup.end())
                lookup.erase(it);
        }
        multimap<int, int, greater<int>> candidates;
        
        auto it = lookup.upper_bound(arr[i]);

        if (it != lookup.end()) {
            int val = it->first;
            for (; it != lookup.end() && it->first == val; ++it) {
                if (candidates.empty() || arr[it->second] >= candidates.begin()->first)
                    candidates.emplace(it->first, it->second);
            }
        }
        
        it = lookup.upper_bound(arr[i]);
        while (it != lookup.end())
            it = lookup.erase(it);
        lookup.emplace(arr[i], i);
        for (auto& p: candidates)
            next[i].emplace_back(p.second);
    }

    int calc(int i) {
        if (dp[i] > 0)
            return dp[i];
        for (int index: next[i]) {            
            dp[i] = max(dp[i], calc(index) + 1);
        }
        dp[i] = max(dp[i], 1);
        return dp[i];
    }
    
    int maxJumps(vector<int>& arr, int d) {
        sz = arr.size();
        res = 0;
        next.resize(sz);
        dp.resize(sz, -1);

        for (int i = 0; i < sz; ++i) {
            process(arr, i, -(d+1));
        }

        lookup.clear();
        for (int i = sz-1; i >= 0; --i) {
            process(arr, i, d+1);
        }

        for (int i = 0; i < sz; ++i) {
            res = max(res, calc(i));
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int d;

    // Output: 4
    arr = {6,4,14,6,8,13,9,7,10,6,12}, d = 2;

    // Output: 1
    //arr = {3,3,3,3,3}, d = 3;

    // Output: 7
    //arr = {7,6,5,4,3,2,1}, d = 1;

    // Output: 2
    //arr = {7,1,7,1,7,1}, d = 2;

    // Output: 1
    //arr = {66}, d = 1;

    // Output: 6
    //arr = {22,29,52,97,29,75,78,2,92,70,90,12,43,17,97,18,58,100,41,32};
    //d = 17;

    // Output: 8
    //arr = {59,8,74,27,92,36,95,78,73,54,75,37,42,15,59,84,66,25,35,61,97,16,6,52,49,18,22,70,5,59,92,85};
    //d = 20;
    
    // OUtput: 12
    //arr = {83,11,83,70,75,45,96,11,80,75,67,83,6,51,71,64,64,42,70,23,11,24,95,65,1,54,31,50,18,16,11,86,2,48,37,34,65,67,4,17,33,70,16,73,57,96,30,26,56,1,16,74,82,77,82,62,32,90,94,33,58,23,23,65,70,12,85,27,38,100,93,49,96,96,77,37,69,71,62,34,4,14,25,37,70,3,67,88,20,30};
    //d = 29;

    // Output: 13
    //arr = {39,1,1,19,40,34,87,44,30,3,89,55,81,97,84,52,10,8,96,69,17,48,93,84,10,48,1,93,65,24,100,26,24,33,52,17,15,26,8,87,69,47,61,58,78,52,2,72,23,9,3,27,36,38,88,20,21,79,5,67,22,24,39,7,17,29,3,97,36,51,91,53,98,48,83,52,14,71,91,46,42,88,44,52,74,8,39,11,48,59,98,34,43,94,46,20,26,62,6,36,59,77,23,93,6,93,64,18,33,69,56,48,54,98,98,53,14,97,47,50,33,87,10,51,92,1,14,27,19,34,83,65,48,44,82,51,81,83,23,8,63,70,76,83,46,84,20,7,37,4,69,63,84,71,91,78,58,25,63,85,98,78,21};
    //d = 62;
    
    cout << sol.maxJumps(arr, d) << endl;

    return 0;
}
