/*
621. Task Scheduler
Medium

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

Constraints:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
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

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        if (n == 0)
            return sz;
        if (sz == 0)
            return 0;
        vector<int> cnt(26, 0);
        for (char ch: tasks)
            ++cnt[ch-'A'];
        int max_val = *max_element(begin(cnt), end(cnt));
        int max_cnt = std::count(begin(cnt), end(cnt), max_val);

        return max(sz, (n + 1) * (max_val-1) + max_cnt);
    }
};

int main() {
    Solution sol;
    vector<char> tasks;
    int n;

    // Ouput: 8
    tasks = {'A','A','A','B','B','B'}, n = 2;
    cout << sol.leastInterval(tasks, n) << endl;

    // Ouput: 6
    tasks = {'A','A','A','B','B','B'}, n = 0;
    cout << sol.leastInterval(tasks, n) << endl;

    // Ouput: 16
    tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'}, n = 2;
    cout << sol.leastInterval(tasks, n) << endl;

    // Ouput: 12
    tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'}, n = 1;
    cout << sol.leastInterval(tasks, n) << endl;
    
    return 0;
}
