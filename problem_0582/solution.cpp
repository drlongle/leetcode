/*
582. Kill Process
Medium

Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

Each process only has one parent process, but may have one or more children processes.
This is just like a tree structure. Only one process has PPID that is 0, which means this
process has no parent process. All the PIDs will be distinct positive integers.

We use two list of integers to represent a list of processes, where the first list contains
PID for each process and the second list contains the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs
of processes that will be killed in the end. You should assume that when a process is killed,
all its children processes will be killed. No order is required for the final answer.

Example 1:
Input:
pid =  [1, 3, 10, 5]
ppid = [3, 0, 5, 3]
kill = 5
Output: [5,10]
Explanation:
           3
         /   \
        1     5
             /
            10
Kill 5 will also kill 10.
Note:
The given kill id is guaranteed to be one of the given PIDs.
n >= 1.
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
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0, n = pid.size(); i < n; ++i) {
            if (!ppid[i]) continue;
            graph[ppid[i]].push_back(pid[i]);
        }
        vector<int> res;
        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            int id = q.front();
            res.push_back(id);
            q.pop();
            for (int nid: graph[id])
                q.push(nid);
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
