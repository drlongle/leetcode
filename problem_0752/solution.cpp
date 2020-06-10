/*
752. Open the Lock
Medium

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".

Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.

Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1

Note:
The length of deadends will be in the range [1, 500].
target will not be in the list deadends.
Every string in deadends and the string target will be a string of 4 digits from the 10,000 possibilities '0000' to '9999'.
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
    int openLock(vector<string>& deadends, string target) {
        bitset<10000> visited;
        unordered_set<string> blocks(begin(deadends), end(deadends));
        string start = "0000";
        if (blocks.count(target) || blocks.count(start))
            return -1;
        queue <pair<string, int>> q;
        q.emplace(start, 0);
        visited.set(0);
        while (!q.empty()) {
            auto [s, d] = q.front();
            q.pop();
            for (int index = 0; index < 4; ++index) {
                if (s == target)
                    return d;
                string ns = s;
                char ch = s[index];
                ns[index] = ch > '0' ? ch - 1 : '9';
                if (!visited.test(stoi(ns)) && !blocks.count(ns)) {
                    q.emplace(ns, d+1);
                    visited.set(stoi(ns));
                }
                ns[index] = ch < '9' ? ch + 1 : '0';
                if (!visited.test(stoi(ns)) && !blocks.count(ns)) {
                    q.emplace(ns, d+1);
                    visited.set(stoi(ns));
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<string> deadends;
    string target;

    // Output: 6
    deadends = {"0201","0101","0102","1212","2002"}, target = "0202";
    cout << sol.openLock(deadends, target) << endl;

    // Output: 1
    deadends = {"8888"}, target = "0009";
    cout << sol.openLock(deadends, target) << endl;

    // Output: -1
    deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"}, target = "8888";
    cout << sol.openLock(deadends, target) << endl;

    // Output: -1
    deadends = {"0000"}, target = "8888";
    cout << sol.openLock(deadends, target) << endl;
    
    return 0;
}
