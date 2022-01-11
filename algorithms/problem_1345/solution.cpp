/*
1345. Jump Game IV
Hard

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you cannot jump outside of the array at any time.

Example 1:
Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

Example 2:
Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You don't need to jump.

Example 3:
Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.

Example 4:
Input: arr = [6,1,9]
Output: 2

Example 5:
Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3

Constraints:
1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8
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
    
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> lookup;
        int sz = arr.size();
        vector<int> offsets{-1, 1};
        queue<pair<int, int>> q;
        vector<int> visited(sz, 0);

        for (int i = 0; i < sz; ++i) {
            if (i > 0 && i < sz-1 && arr[i-1] == arr[i] && arr[i] == arr[i+1])
                continue;
            lookup[arr[i]].emplace_back(i);
        }
        
        q.emplace(0, 0);
        visited[0] = 1;
        while (!q.empty()) {
            auto& p = q.front();
            int i = p.first;
            if (i == sz-1)
                return p.second;
            for (auto offset: offsets) {
                int j = i + offset;
                if (j >= 0 && j < sz && !visited[j]) {
                    visited[j] = 1;
                    q.emplace(j, p.second + 1);
                }
            }
            for (int j: lookup[arr[i]]) {
                if (j !=i && !visited[j]) {
                    visited[j] = 1;
                    q.emplace(j, p.second + 1);
                }
            }
            q.pop();
        }
        return sz-1;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: 3
    arr = {100,-23,-23,404,100,23,23,23,3,404};

    // Output: 0
    arr = {7};

    // Output: 1
    arr = {7,6,9,6,9,6,9,7};

    // Output: 2
    arr = {6,1,9};

    // Output: 3
    arr = {11,22,7,7,7,7,7,7,7,22,13};

    // Output: 5
    arr = {-76,3,66,-32,64,2,-19,-8,-5,-93,80,-5,-76,-78,64,2,16};
    
    cout << sol.minJumps(arr) << endl;
        
    return 0;
}
