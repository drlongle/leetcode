/*
1136. Parallel Courses
Difficulty: Hard

There are N courses, labelled from 1 to N.
We are given relations[i] = [X, Y], representing a prerequisite relationship between
course X and course Y: course X has to be studied before course Y.
In one semester you can study any number of courses as long as you have studied all
the prerequisites for the course you are studying.

Return the minimum number of semesters needed to study all courses.
If there is no way to study all the courses, return -1.

Example 1:
Input: N = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation: 
In the first semester, courses 1 and 2 are studied. In the second semester, course 3 is studied.

Example 2:
Input: N = 3, relations = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: 
No course can be studied because they depend on each other.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

enum class State {
    UNVISITED,
    VISITING,
    VISITED
};

struct Node {
    Node(int id): m_id(id), dist(0), m_state(State::UNVISITED) {}
    int m_id;
    int dist;
    State m_state;
    vector<int> depends;
};

class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        for (int i = 0; i <= N; ++i)
            nodes.emplace_back(i);
        for (auto& rel: relations) {
            nodes[rel[1]].depends.emplace_back(rel[0]);
        }
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            int t = DFS(i);
            if (t < 0)
                return -1;
            res = max(res, t);
        }
        
        return res;
    }

    int DFS(int id)
    {
        auto& node = nodes[id];
        if (node.m_state == State::VISITED)
            return node.dist;
        else if (node.m_state == State::VISITING)
            return -1;
        node.m_state = State::VISITING;
        int res = 0;
        for (int n: node.depends) {
            int t = DFS(n);
            if (t < 0)
                return -1;
            res = max(res, t);
        }
        node.m_state = State::VISITED;

        return node.dist = 1 + res;
    }

    vector<Node> nodes;
};

int main()
{
    Solution sol;
    vector<vector<int>> relations;
    int N;
    
    // Expected: 2
    N = 3, relations = {{1,3},{2,3}};
    
    // Expected: -1
    N = 3, relations = {{1,2},{2,3},{3,1}};

    cout << "Result: " << sol.minimumSemesters(N, relations) << endl;

    return 0;
}

