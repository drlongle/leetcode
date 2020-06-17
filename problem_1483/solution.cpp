/*
1483. Kth Ancestor of a Tree Node
Hard

You are given a tree with n nodes numbered from 0 to n-1 in the form of a parent array where parent[i] is the parent of node i. The root of the tree is node 0.

Implement the function getKthAncestor(int node, int k) to return the k-th ancestor of the given node. If there is no such ancestor, return -1.

The k-th ancestor of a tree node is the k-th node in the path from that node to the root.

Example:
Input:
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

Output:
[null,1,0,-1]

Explanation:
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
treeAncestor.getKthAncestor(3, 1);  // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2);  // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3);  // returns -1 because there is no such ancestor

Constraints:
1 <= k <= n <= 5*10^4
parent[0] == -1 indicating that 0 is the root node.
0 <= parent[i] < n for all 0 < i < n
0 <= node < n
There will be at most 5*10^4 queries.
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

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent): lookup(parent), dp(n), negatives(n, numeric_limits<int>::max())
    {
    }

    int getKthAncestor(int node, int k) {
        if (k == 0)
            return node;
        if (negatives[node] <= k)
            return -1;
        int res = -1;
        auto it = dp[node].lower_bound(k);
        if (it != dp[node].end())  {
            res = getKthAncestor(it->second, k - it->first);
        } else {
            int ancestor = lookup[node];
            if (ancestor >= 0)
                res = getKthAncestor(ancestor, k - 1);
        }
        if (res >= 0)
            return dp[node][k] = res;        
        negatives[node] = min(k, negatives[node]);
        return res;
        
    }
    vector<int> lookup;
    vector<map<int, int, greater<int>>> dp;
    vector<int> negatives;
};

void test_1() {
    /*
    Expected: [null,1,0,-1]
    ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
    [[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]
    */
    vector<int> parent;
    parent = {-1,0,0,1,1,2,2};
    int n = 7;
    TreeAncestor tree(n, parent);
    cout << tree.getKthAncestor(3, 1) << endl;
    cout << tree.getKthAncestor(5, 2) << endl;
    cout << tree.getKthAncestor(6, 3) << endl;
}

void test_2() {
    /*
Input:
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[5,[-1,0,0,0,3]],[1,5],[3,2],[0,1],[3,1],[3,5]]
Output:
[null,-1,0,-1,0,-1]
Expected:
[null,-1,-1,-1,0,-1]
     */

    vector<int> parent;
    parent = {-1,0,0,0,3};
    int n = 5;
    TreeAncestor tree(n, parent);
    cout << tree.getKthAncestor(1, 5) << endl;
    cout << tree.getKthAncestor(3, 2) << endl;
    cout << tree.getKthAncestor(0, 1) << endl;
    cout << tree.getKthAncestor(3, 1) << endl;
    cout << tree.getKthAncestor(3, 5) << endl;
}

int main() {
    test_1();
    test_2();

    return 0;
}
