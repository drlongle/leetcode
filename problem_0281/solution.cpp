/*
281. Zigzag Iterator
Medium

Given two vectors of integers v1 and v2, implement an iterator to return their elements alternately.

Implement the ZigzagIterator class:

ZigzagIterator(List<int> v1, List<int> v2) initializes the object with the two vectors v1 and v2.
boolean hasNext() returns true if the iterator still has elements, and false otherwise.
int next() returns the current element of the iterator and moves the iterator to the next element.

Example 1:
Input: v1 = [1,2], v2 = [3,4,5,6]
Output: [1,3,2,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements
returned by next should be: [1,3,2,4,5,6].

Example 2:
Input: v1 = [1], v2 = []
Output: [1]

Example 3:
Input: v1 = [], v2 = [1]
Output: [1]

Constraints:
0 <= v1.length, v2.length <= 1000
1 <= v1.length + v2.length <= 2000
-2^31 <= v1[i], v2[i] <= 2^31 - 1

Follow up: What if you are given k vectors? How well can your code be extended to such cases?
Clarification for the follow-up question:
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right
to you, replace "Zigzag" with "Cyclic".
Example:
Input: v1 = [1,2,3], v2 = [4,5,6,7], v3 = [8,9]
Output: [1,4,8,2,5,9,3,6,7]
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

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>&v2) {
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i){
            if(i < v1.size())
                v.push_back(v1[i]);
            if (i < v2.size())
                v.push_back(v2[i]);
        }
    }

    int next() {
        int n = v.front();
        v.pop_front();
        return n;
    }

    bool hasNext() {
        return v.size();
    }

    deque<int> v;
};

int main() {
    Solution sol;

    return 0;
}
