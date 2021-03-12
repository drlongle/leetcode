/*
547. Number of Provinces
Medium

There are n cities. Some of them are connected, while some are not. If city a is connected directly with
city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and
the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

Constraints:
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector <int> visited (n, 0);
        int id = 0;
        for (int i = 0;i < n; ++i) {
            if (visited[i] == 0) {
                visited[i] = ++id;
                queue<int> q;
                q.push(i);
                while (q.size()) {
                    int k = q.front();
                    q.pop();

                    for (int j = i+1; j < n; ++j) {
                        if (k != j && !visited[j] && j != i && isConnected[j][k]) {
                            q.emplace(j);
                            visited[j] = id;
                        }
                    }
                }
            }
        }

        return id;
    }
};

int main() {
    Solution sol;

    return 0;
}
