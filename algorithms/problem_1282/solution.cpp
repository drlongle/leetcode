/*
1282. Group the People Given the Group Size They Belong To
Medium

There are n people whose IDs go from 0 to n - 1 and each person belongs exactly to one group. Given the array groupSizes of length n telling the group size each person belongs to, return the groups there are and the people's IDs each group includes.

You can return any solution in any order and the same applies for IDs. Also, it is guaranteed that there exists at least one solution. 

Example 1:
Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation: 
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].

Example 2:
Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]

Constraints:

groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n
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
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int sz = groupSizes.size();
        map<int, vector<int>> groups;
        for (int i = 0; i < sz; ++i) {
            groups[groupSizes[i]].emplace_back(i);
        }

        vector<vector<int>> res;
        for (auto& gr: groups) {
            int gz = gr.first;
            vector<int> group;
            sz = gr.second.size();
            for (int i = 0; i < sz; ++i) {
                group.emplace_back(gr.second[i]);
                if ((i +1) % gz == 0) {
                    res.emplace_back(group);
                    group.clear();
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
