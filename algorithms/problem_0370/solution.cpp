/*
370. Range Addition
Medium

You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

You have an array arr of length length with all zeros, and you have some operation to apply on arr.
In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi]
by inci.

Return arr after applying all the updates.

Example 1:
Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]

Example 2:
Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
Output: [0,-4,2,2,2,4,4,-4,-4,-4]

Constraints:
1 <= length <= 10^5
0 <= updates.length <= 10^4
0 <= startIdxi <= endIdxi < length
-1000 <= inci <= 1000
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class SegmentTree {
public:
    SegmentTree(int n)
    {
        int x = ceil(log2(n));
        limit = pow(2, x) - 1;
        data.resize(2 * pow(2, x) - 1, 0);
    }

    void add(size_t index, int low, int high, int begin, int end, int val)
    {
        if (low > end || begin > high || index >= data.size())
            return;

        if (begin <= low && high <= end) {
            data[index] += val;
        }

        int mid = (low + high) / 2;
        add(2 * index + 1, low, mid, begin, end, val);
        add(2 * index + 2, mid + 1, high, begin, end, val);
    }

    void add(int begin, int end, int val)
    {
        add(0, 0, limit, begin, end, val);
    }

    int query(size_t index, int low, int high, int begin, int end)
    {
        if (low > end || begin > high || index >= data.size())
            return 0;

        if (begin <= low && high <= end) {
            return data[index];
        }

        int mid = (low + high) / 2;
        return query(2 * index + 1, low, mid, begin, end) +
            query(2 * index + 2, mid + 1, high, begin, end);
    }

    int query(int pos)
    {
        return query(0, 0, limit, pos, pos);
    }

    vector<int> data;
    int limit;
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates)
    {
        SegmentTree segmentTree(length);
        sort(begin(updates), end(updates));
        for (int i = 0, sz = updates.size(); i < sz; ) {
            int j = i + 1;
            while (j < sz && updates[i] == updates[j])
                ++j;
            segmentTree.add(updates[i][0], updates[i][1], updates[i][2] * (j - i));
            i = j;
        }

        vector<int> res(length);
        for (int i = 0; i < length; ++i) {
            res[i] = segmentTree.query(i);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> updates;
    vector<int> res;
    int length;

    // Output: {-2,0,3,5,3}
    length = 5, updates = {{1,3,2},{2,4,3},{0,2,-2}};
    res = sol.getModifiedArray(length, updates);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {0,-4,2,2,2,4,4,-4,-4,-4}
    length = 10, updates = {{2,4,6},{5,6,8},{1,9,-4}};
    res = sol.getModifiedArray(length, updates);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
