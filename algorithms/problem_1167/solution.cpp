/*
1167. Minimum Cost to Connect Sticks
Difficulty: Medium

You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.
You perform this action until there is one stick remaining. Return the minimum cost of connecting
all the given sticks into one stick in this way.

Example 1:
Input: sticks = [2,4,3]
Output: 14

Example 2:
Input: sticks = [1,8,3,5]
Output: 30
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
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        for (auto& stick: sticks)
            pq.push(stick);
        while (pq.size() > 1) {
            int cost = pq.top();
            pq.pop();
            cost += pq.top();
            pq.pop();
            res += cost;
            pq.push(cost);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> sticks;

    sticks = {2,4,3};
    cout << "Result: " << sol.connectSticks(sticks) << endl;
    
    return 0;
}
