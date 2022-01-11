/*
1361. Validate Binary Tree Nodes
Medium

You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
Note that the nodes have no values and that we only use the node numbers in this problem.

Example 1:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true

Example 2:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false

Example 3:
Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false

Example 4:
Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
Output: false

Constraints:
1 <= n <= 10^4
leftChild.length == rightChild.length == n
-1 <= leftChild[i], rightChild[i] <= n - 1
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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, 0);
        int index;
        for (int i = 0; i < n; ++i) {
            index = leftChild[i];
            if (index >= 0)
                ++parent[index];
            index = rightChild[i];
            if (index >= 0)
                ++parent[index];
        }
        if (count_if(begin(parent), end(parent), [] (int p) {return p == 0;}) != 1)
            return false;
        if (count_if(begin(parent), end(parent), [] (int p) {return p >= 2;}) > 0)
            return false;
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> leftChild, rightChild;
    int n;

    // Output: true
    n = 4, leftChild = {1,-1,3,-1}, rightChild = {2,-1,-1,-1};

    // Output: false
    //n = 4, leftChild = {1,-1,3,-1}, rightChild = {2,3,-1,-1};

    // Output: false
    //n = 2, leftChild = {1,0}, rightChild = {-1,-1};

    // Output: false
    n = 6, leftChild = {1,-1,-1,4,-1,-1}, rightChild = {2,-1,-1,5,-1,-1};

    cout << boolalpha << sol.validateBinaryTreeNodes(n, leftChild, rightChild) << endl;
    
    return 0;
}
