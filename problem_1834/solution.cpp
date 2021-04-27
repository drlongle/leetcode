/*
1834. Single-Threaded CPU
Medium

You are given n tasks labeled from 0 to n - 1 represented by a 2D integer array tasks,
where tasks[i] = [enqueueTimei, processingTimei] means that the ith task will be available to process
at enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time.
If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.

Example 1:
Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows:
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.

Example 2:
Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
Output: [4,3,2,0,1]
Explanation: The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.

Constraints:
tasks.length == n
1 <= n <= 10^5
1 <= enqueueTimei, processingTimei <= 10^9
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    struct Task {
        Task(int s, int d, int i): start(s), duration(d), id(i) {}
        int start, duration, id;
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<Task> entries;
        int n = tasks.size();
        for (int i = 0; i < n; ++i) {
            entries.emplace_back(tasks[i][0], tasks[i][1], i);
        }
        auto lambda = [] (auto& e1, auto& e2)
                {return e1.start < e2.start || (e1.start == e2.start && e1.duration <= e2.duration);};
        auto lambda2 = [] (auto& e1, auto& e2)
                {return e1.duration > e2.duration || (e1.duration == e2.duration && e1.id > e2.id);};
        sort(begin(entries), end(entries), lambda);
        priority_queue<Task, vector<Task>, decltype(lambda2)> pq(lambda2);

        vector<int> res;
        long long t = 0, i = 0;

        while (i < n || pq.size()) {
            if (pq.empty()) {
                pq.emplace(entries[i++]);
            }

            auto& e = pq.top();
            t = max(t, (long long) e.start);
            t += e.duration;
            res.push_back(e.id);
            pq.pop();

            while (i < n && entries[i].start <= t) {
                pq.emplace(entries[i++]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> tasks;
    vector<int> res;

    tasks = {{1,2},{2,4},{3,2},{4,1}};
    res = sol.getOrder(tasks);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    tasks = {{7,10},{7,12},{7,5},{7,4},{7,2}};
    res = sol.getOrder(tasks);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;


    return 0;
}
