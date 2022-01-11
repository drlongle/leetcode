/*
683. K Empty Slots
Hard

You have n bulbs in a row numbered from 1 to n. Initially, all the bulbs are turned off. We turn on
exactly one bulb every day until all bulbs are on after n days.

You are given an array bulbs of length n where bulbs[i] = x means that on the (i+1)th day, we will turn on the bulb
at position x where i is 0-indexed and x is 1-indexed.

Given an integer k, return the minimum day number such that there exists two turned on bulbs that have
exactly k bulbs between them that are all turned off. If there isn't such day, return -1.

Example 1:
Input: bulbs = [1,3,2], k = 1
Output: 2
Explanation:
On the first day: bulbs[0] = 1, first bulb is turned on: [1,0,0]
On the second day: bulbs[1] = 3, third bulb is turned on: [1,0,1]
On the third day: bulbs[2] = 2, second bulb is turned on: [1,1,1]
We return 2 because on the second day, there were two on bulbs with one off bulb between them.

Example 2:
Input: bulbs = [1,2,3], k = 1
Output: -1

Constraints:
n == bulbs.length
1 <= n <= 2 * 10^4
1 <= bulbs[i] <= n
bulbs is a permutation of numbers from 1 to n.
0 <= k <= 2 * 10^4
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

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        set<int> nums;
        for (int i = 0, sz = bulbs.size(); i < sz; ++i) {
            auto it = nums.insert(bulbs[i]).first;
            if (it != nums.begin()) {
                auto pr = prev(it);
                if(*it - *pr == k + 1)
                    return i + 1;
            }
            auto ne = next(it);
            if (ne != end(nums) && *ne - *it == k + 1)
                return i + 1;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    return 0;
}
