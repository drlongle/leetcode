/*
1383. Maximum Performance of a Team
Hard

There are n engineers numbered from 1 to n and two arrays: speed and efficiency, where speed[i] and efficiency[i] represent the speed and efficiency for the i-th engineer respectively. Return the maximum performance of a team composed of at most k engineers, since the answer can be a huge number, return this modulo 10^9 + 7.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers. 

Example 1:
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.

Example 2:
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.

Example 3:
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72

Constraints:
1 <= n <= 10^5
speed.length == n
efficiency.length == n
1 <= speed[i] <= 10^5
1 <= efficiency[i] <= 10^8
1 <= k <= n
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
#include <memory>
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
    struct Entry {
        Entry(int v, int l): value(v), level(l) {}
        bool operator<(const Entry& other) const {
            return level < other.level || (level == other.level && value < other.value);
        }
        int value, level;
    };
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<Entry> entries;
        priority_queue<int, vector<int>, greater<int>> nums;
        for (int i = 0; i < n; ++i)
            entries.emplace(speed[i], efficiency[i]);
        long long res = 0, sum = 0;
        int level = numeric_limits<int>::max();
        for (int i = 0; i < k; ++i) {
            const auto& [val, elevel] = entries.top();
            level = min(level, elevel);
            nums.push(val);
            sum += val;
            res = max(res, level*sum);
            entries.pop();
        }

        while (!entries.empty()) {
            const auto& [val, elevel] = entries.top();
            level = min(level, elevel);
            nums.push(val);
            sum += val - nums.top();
            nums.pop();
            entries.pop();
            res = max(res, level*sum);
        }
        
        return res % 1000000007;
    }
};

int main() {
    Solution sol;
    int n, k;
    vector<int> speed, efficiency;

    for (int i = 5; i <= 6; ++i) {
        n = 6, speed = {2,10,3,1,5,8}, efficiency = {5,4,3,9,7,2}, k = i;
        cout << sol.maxPerformance(n, speed, efficiency, k) << endl;
    }

    return 0;
}
