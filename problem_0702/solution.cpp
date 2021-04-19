/*
702. Search in a Sorted Array of Unknown Size
Medium

Given an integer array sorted in ascending order, write a function to search target in nums.
If target exists, then return its index, otherwise return -1. However, the array size is unknown to you.
You may only access the array using an ArrayReader interface, where ArrayReader.get(k) returns
the element of the array at index k (0-indexed).

You may assume all integers in the array are less than 10000, and if you access
the array out of bounds, ArrayReader.get will return 2147483647.

Example 1:
Input: array = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: array = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

Constraints:
You may assume that all elements in the array are unique.
The value of each element in the array will be in the range [-9999, 9999].
The length of the array will be in the range [1, 10^4].
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

class ArrayReader {
public:
    int get(int index) {
        return index;
    }
};

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int lo = 0, hi = 1;
        while (true) {
            if (reader.get(hi) == INT_MAX)
                break;
            hi *= 2;
        }

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int val = reader.get(mid);
            if (val == target)
                return mid;
            if (val > target)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    return 0;
}
