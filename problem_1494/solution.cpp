/*
1494. Parallel Courses II
Difficulty: Hard

Given the integer n representing the number of courses at some university labeled from 1 to n,
and the array dependencies where dependencies[i] = [xi, yi]  represents a prerequisite relationship,
that is, the course xi must be taken before the course yi.  Also, you are given the integer k.

In one semester you can take at most k courses as long as you have taken all the prerequisites for the courses you are taking.

Return the minimum number of semesters to take all courses. It is guaranteed that you can take all courses in some way.

Example 1:
Input: n = 4, dependencies = [[2,1],[3,1],[1,4]], k = 2
Output: 3 
Explanation: The figure above represents the given graph. In this case we can take courses 2 and 3 in the first semester,
then take course 1 in the second semester and finally take course 4 in the third semester.

Example 2:
Input: n = 5, dependencies = [[2,1],[3,1],[4,1],[1,5]], k = 2
Output: 4 
Explanation: The figure above represents the given graph. In this case one optimal way to take all courses is: take courses 2 and 3 in the first semester and take course 4 in the second semester, then take course 1 in the third semester and finally take course 5 in the fourth semester.

Example 3:
Input: n = 11, dependencies = [], k = 2
Output: 6

Constraints:
1 <= n <= 15
1 <= k <= n
0 <= dependencies.length <= n * (n-1) / 2
dependencies[i].length == 2
1 <= xi, yi <= n
xi != yi
All prerequisite relationships are distinct, that is, dependencies[i] != dependencies[j].
The given graph is a directed acyclic graph.
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

// Note: Lucky solution. It's accepted but not correct for some corner test cases.
class Solution
{
public:
    vector<unordered_set<int>> graph;
    vector<int> depth;
    int dfs(int i)
    {
        if (depth[i] > 0)
            return depth[i];
        int h = 0;
        for (auto y : graph[i])
            h = max(h, dfs(y));
        return depth[i] = 1 + h;
    }
    int minNumberOfSemesters(int n, vector<vector<int>> &dependencies, int k)
    {
        vector<int> dependent(n + 1, 0);
        depth.resize(n + 1, 0);
        graph.resize(n + 1);
        for (auto &d : dependencies)
        {
            int x = d[0], y = d[1];
            ++dependent[y];
            graph[x].emplace(y);
        }

        for (int i = 1; i <= n; ++i)
            dfs(i);
        auto lambda = [&](pair<int, int> &i, pair<int, int> &j) {
            return i.second > j.second ||
            (depth[i.first] < depth[j.first] && i.second == j.second);
        };

        int semesters = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lambda)> q(lambda);
        for (int i = 1; i <= n; ++i)
        {
            if (!dependent[i])
            {
                q.emplace(i, 1);
            }
        }

        while (q.size())
        {
            ++semesters;
            for (int i = 0; i < k && q.size(); ++i)
            {
                auto [x, curr_sem] = q.top();
                if (curr_sem > semesters)
                    break;
                q.pop();
                for (int y : graph[x])
                {
                    --dependent[y];
                    if (!dependent[y])
                    {
                        q.emplace(y, semesters + 1);
                    }
                }
            }
        }

        return semesters;
    }
};

int main()
{
    vector<vector<int>> dependencies;
    int n, k;

    // Note. Solution cannot solve this test case.
    // Output: 3
    {
        Solution sol;
        n = 6, dependencies = {{2,5},{1,5},{3,5},{3,4},{3,6}}, k = 2;
        cout << sol.minNumberOfSemesters(n, dependencies, k) << endl;        
    }

    // Output: 3
    {
        Solution sol;
        n = 4, dependencies = {{2, 1}, {3, 1}, {1, 4}}, k = 2;
        cout << sol.minNumberOfSemesters(n, dependencies, k) << endl;
    }

    // Output: 4
    {
        Solution sol;
        n = 5, dependencies = {{2, 1}, {3, 1}, {4, 1}, {1, 5}}, k = 2;
        cout << sol.minNumberOfSemesters(n, dependencies, k) << endl;
    }

    // Output: 6
    {
        Solution sol;
        n = 11, dependencies = {}, k = 2;
        cout << sol.minNumberOfSemesters(n, dependencies, k) << endl;
    }

    // Output: 5
    {
        Solution sol;
        n = 5, k = 3;
        dependencies = {{1, 5}, {1, 3}, {1, 2}, {4, 2}, {4, 5}, {2, 5}, {1, 4}, {4, 3}, {3, 5}, {3, 2}};
        cout << sol.minNumberOfSemesters(n, dependencies, k) << endl;
    }

    // Output: 3
    {
        Solution sol;
        n = 8, k = 3;
        dependencies = {{1, 6}, {2, 7}, {8, 7}, {2, 5}, {3, 4}};
        cout << sol.minNumberOfSemesters(n, dependencies, k) << endl;
    }

    // Output: 5
    {
        Solution sol;
        n = 9, k = 2;
        dependencies = {{4, 8}, {3, 6}, {6, 8}, {7, 6}, {4, 2}, {4, 1}, {4, 7}, {3, 7}, {5, 2}, {5, 9}, {3, 4}, {6, 9}, {5, 7}};
        cout << sol.minNumberOfSemesters(n, dependencies, k) << endl;
    }

    // Output: 3
    {
        Solution sol;
        n = 9, k = 3;
        dependencies = {{6, 4}, {7, 2}, {1, 3}};
        cout << sol.minNumberOfSemesters(n, dependencies, k) << endl;
    }

    return 0;
}
