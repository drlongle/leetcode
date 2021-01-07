/*
339. Nested List Weight Sum
Easy

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: 10
Explanation: Four 1's at depth 2, one 2 at depth 1.

Example 2:
Input: [1,[4,[6]]]
Output: 27
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27.
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

class NestedInteger {
public:
    bool isInteger() const {
        return true;
    }

    int getInteger() const {
        return 0;
    }

    const vector<NestedInteger> nestedList;

    const vector<NestedInteger> &getList() const {
        return nestedList;
    }
};

class Solution {
public:
    int sum;

    void DFS(const NestedInteger& nestedList, int factor) {
        if (nestedList.isInteger()) {
            sum += factor * nestedList.getInteger();
        } else {
            for (auto& list: nestedList.getList()) {
                DFS(list, factor + 1);
            }
        }
    }

    int depthSum(vector<NestedInteger>& nestedList) {
        sum = 0;
        for (const auto& list: nestedList) {
            DFS(list, 1);
        }

        return sum;
    }
};

int main() {
    Solution sol;

    return 0;
}
