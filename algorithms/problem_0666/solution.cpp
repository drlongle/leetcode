/*
666. Path Sum IV
Medium

If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:
The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8.
The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.

Given a list of ascending three-digits integers representing a binary tree with the depth smaller than 5,
you need to return the sum of all paths from the root towards the leaves.

It's guaranteed that the given list represents a valid connected binary tree.

Example 1:
Input: [113, 215, 221]
Output: 12
Explanation:
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.

Example 2:
Input: [113, 221]
Output: 4
Explanation:
The tree that the list represents is:
    3
     \
      1

The path sum is (3 + 1) = 4.
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

    unordered_map<int, unordered_map<int, int>> nodes;

    bool is_leaf(int level, int pos) {
        auto& m = nodes[level+1];
        unordered_map<int, int>::iterator it;
        return m.find(2 * (pos-1) + 1) == m.end() &&
            m.find(2 * (pos-1) + 2) == m.end();
    }

    int get_sum(int level, int pos) {
        return nodes[level][pos] + ((level > 1) ? get_sum(level-1, (pos+1) / 2) : 0);
    }

    int pathSum(vector<int>& nums) {
        for (int num: nums) {
            int level = num / 100;
            int pos = (num % 100) / 10;
            int val = (num % 10);
            nodes[level][pos] = val;
        }

        int res = 0;
        for (auto& [level, m]: nodes) {
            for (auto& [pos, val]: m) {
                if (is_leaf(level, pos))
                   res += get_sum(level, pos);
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums;

    // Output: 12
    {
        Solution sol;
        nums = {113, 215, 221};
        cout << sol.pathSum(nums) << endl;
    }

    // Output: 4
    {
        Solution sol;
        nums = {113, 221};
        cout << sol.pathSum(nums) << endl;
    }

    return 0;
}
