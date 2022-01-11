/*
457. Circular Array Loop
Medium

You are given a circular array nums of positive and negative integers. If a number k at an index is positive, then move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

Determine if there is a loop (or a cycle) in nums. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.

Example 1:
Input: [2,-1,1,2,2]
Output: true
Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's length is 3.

Example 2:
Input: [-1,2]
Output: false
Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle, because the cycle's length is 1. By definition the cycle's length must be greater than 1.

Example 3:
Input: [-2,1,-1,-2,-2]
Output: false
Explanation: The movement from index 1 -> 2 -> 1 -> ... is not a cycle, because movement from index 1 -> 2 is a forward movement, but movement from index 2 -> 1 is a backward movement. All movements in a cycle must follow a single direction
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
    int sign(int n) {
        return n > 0 ? 1 : -1;
    }

    bool DFS(vector<int>& nums, int origin) {
        set<int> current;
        int sig = sign(nums[origin]);
        int nsize = static_cast<int>(nums.size());
        int i = origin;
        while (true) {
            current.emplace(i);
            int next = i + nums[i];
            while (next < 0 || next >= nsize) {
                if (next < 0)
                    next += nsize;
                else
                    next -= nsize;
            }
            if (current.count(next))
                return (current.size() > 1 && origin == next);
            if (sign(nums[next]) != sig)
                return false;
            i = next;
        }

        visited.emplace(origin);
        return false;
    }

    bool circularArrayLoop(vector<int>& nums) {
        visited.clear();
        for (size_t i = 0; i < nums.size(); ++i)
            if (visited.count(i) == 0 && DFS(nums, i))
                return true;
        return false;
    }

    set<int> visited;
};


int main() {
    Solution sol;
    return 0;
}
