/*
508. Most Frequent Subtree Sum
Medium

Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.

Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
#include <memory>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sum(TreeNode* node) {
        if (!node)
            return 0;
        int s = node->val;
        s += sum(node->left);
        s += sum(node->right);
        max_count = max(max_count, ++cnt[s]);
        return s;
    }
    unordered_map<int, int> cnt;
    int max_count;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        max_count = 0;
        vector<int> res;
        for (auto& [val, c]: cnt) {
            if (c == max_count)
                res.emplace_back(val);
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
