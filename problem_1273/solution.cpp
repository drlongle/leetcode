/*
1273. Delete Tree Nodes
Medium

A tree rooted at node 0 is given as follows:
The number of nodes is nodes;
The value of the i-th node is value[i];
The parent of the i-th node is parent[i].
Remove every subtree whose sum of values of nodes is zero.
After doing so, return the number of nodes remaining in the tree.

Example 1:
Input: nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-1]
Output: 2

Constraints:
1 <= nodes <= 10^4
-10^5 <= value[i] <= 10^5
parent.length == nodes
parent[0] == -1 which indicates that 0 is the root.
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
    void deleteNode(int id) {
        deleted.emplace(id);
        for (auto& cid: children[id])
            deleteNode(cid);
    }

    int getSum(int id, vector<int>& value) {
        auto it = sum.find(id);
        if (it != sum.end())
            return it->second;
        int res = value[id];
        for (auto& cid: children[id])
            res += getSum(cid, value);
        sum[id] = res;
        if (res == 0)
            deleteNode(id);
        return res;
    }

    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        children.resize(nodes);
        for (int n = 0; n < nodes; ++n) {
            int par = parent[n];
            if (par >= 0)
                children[par].emplace(n);
        }
        for (int n = 0; n < nodes; ++n)
            getSum(n, value);
        return nodes - deleted.size();
    }

    vector<set<int>> children;
    set<int> deleted;
    map<int, int> sum;
};

int main() {
    Solution sol;
    return 0;
}
