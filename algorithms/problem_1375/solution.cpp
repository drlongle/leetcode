/*
1375. Bulb Switcher III
Medium

There is a room with n bulbs, numbered from 1 to n, arranged in a row from left to right. Initially, all the bulbs are turned off.

At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. A bulb change color to blue only if it is on and all the previous bulbs (to the left) are turned on too.

Return the number of moments in which all turned on bulbs are blue.

Example 1:
Input: light = [2,1,3,5,4]
Output: 3
Explanation: All bulbs turned on, are blue at the moment 1, 2 and 4.

Example 2:
Input: light = [3,2,4,1,5]
Output: 2
Explanation: All bulbs turned on, are blue at the moment 3, and 4 (index-0).

Example 3:
Input: light = [4,1,2,3]
Output: 1
Explanation: All bulbs turned on, are blue at the moment 3 (index-0).
Bulb 4th changes to blue at the moment 3.

Example 4:
Input: light = [2,1,4,3,6,5]
Output: 3

Example 5:
Input: light = [1,2,3,4,5,6]
Output: 6

Constraints:
n == light.length
1 <= n <= 5 * 10^4
light is a permutation of  [1, 2, ..., n]
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
    int numTimesAllBlue(vector<int>& light) {
        int res = 0, max_seen = 0;
        unordered_set<int> seen;
        for (auto n: light) {
            max_seen = max(n, max_seen);
            seen.emplace(n);
            res += (seen.size() == max_seen);
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> light;

    // Output: 3
    light = {2,1,3,5,4};
    cout << sol.numTimesAllBlue(light) << endl;
    
    // Output: 2
    light = {3,2,4,1,5};
    cout << sol.numTimesAllBlue(light) << endl;
    
    // Output: 1
    light = {4,1,2,3};
    cout << sol.numTimesAllBlue(light) << endl;
    
    // Output: 3
    light = {2,1,4,3,6,5};
    cout << sol.numTimesAllBlue(light) << endl;
    
    // Output: 6
    light = {1,2,3,4,5,6};
    cout << sol.numTimesAllBlue(light) << endl;
    
    return 0;
}
