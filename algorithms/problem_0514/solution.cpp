/*
514. Freedom Trail
Hard

In the video game Fallout 4, the quest "Road to Freedom" requires players to
reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a
specific keyword to open the door.

Given a string ring that represents the code engraved on the outer ring and
another string key that represents the keyword that needs to be spelled, return
the minimum number of steps to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at the "12:00" direction.
You should spell all the characters in key one by one by rotating ring clockwise
or anticlockwise to make each character of the string key aligned at the "12:00"
direction and then by pressing the center button.

At the stage of rotating the ring to spell the key character key[i]:

You can rotate the ring clockwise or anticlockwise by one place, which counts as
one step. The final purpose of the rotation is to align one of ring's characters
at the "12:00" direction, where this character must equal key[i]. If the
character key[i] has been aligned at the "12:00" direction, press the center
button to spell, which also counts as one step. After the pressing, you could
begin to spell the next character in the key (next stage). Otherwise, you have
finished all the spelling.

Example 1:
Input: ring = "godding", key = "gd"
Output: 4
Explanation:
For the first key character 'g', since it is already in place, we just need 1
step to spell this character. For the second key character 'd', we need to
rotate the ring "godding" anticlockwise by two steps to make it become
"ddinggo". Also, we need 1 more step for spelling. So the final output is 4.

Example 2:
Input: ring = "godding", key = "godding"
Output: 13

Constraints:
1 <= ring.length, key.length <= 100
ring and key consist of only lower case English letters.
It is guaranteed that key could always be spelled by rotating ring.

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

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    map<pair<int, int>, int> dp;
    int ringsz;
    int findRotateSteps(string &ring, string &key, int rindex, int kindex) {
        auto k = std::pair<int, int>(rindex, kindex);
        auto it = dp.find(k);
        if (it != dp.end())
            return it->second;
        if (kindex == key.size())
            return dp[k] = 0;
        char ch = key[kindex];
        if (ch == ring[rindex])
            return dp[k] = 1 + findRotateSteps(ring, key, rindex, kindex + 1);

        auto &lookup = lookups[ch - 'a'];
        auto lit = lower_bound(lookup.begin(), lookup.end(), rindex);
        int res = INT_MAX;
        if (lit != lookup.end()) {
            int dist = *lit - rindex;
            dist = min(dist, ringsz - dist);
            res = findRotateSteps(ring, key, *lit, kindex + 1) + dist + 1;
            if (lit != lookup.begin()) {
                dist = abs(*(lit - 1) - rindex);
                dist = min(dist, ringsz - dist);
                res = min(res,
                          findRotateSteps(ring, key, *(lit - 1), kindex + 1) +
                              dist + 1);
            } else {
                dist = abs(lookup.back() - rindex);
                dist = min(dist, ringsz - dist);
                res = min(
                    res, findRotateSteps(ring, key, lookup.back(), kindex + 1) +
                             dist + 1);
            }
        } else {
            int dist = abs(lookup[0] - rindex);
            dist = min(dist, ringsz - dist);
            res = min(res, findRotateSteps(ring, key, lookup[0], kindex + 1) +
                               dist + 1);

            dist = abs(lookup.back() - rindex);
            dist = min(dist, ringsz - dist);
            res =
                min(res, findRotateSteps(ring, key, lookup.back(), kindex + 1) +
                             dist + 1);
        }

        // cout << "rindex: " << rindex << "; kindex: " << kindex << " -> " <<
        // res << endl;

        return dp[k] = res;
    }

    vector<vector<int>> lookups;
    int findRotateSteps(string ring, string key) {
        lookups.resize(26);
        ringsz = ring.size();
        for (int i = 0, sz = ring.size(); i < sz; ++i)
            lookups[ring[i] - 'a'].push_back(i);
        return findRotateSteps(ring, key, 0, 0);
    }
};

int main() {
    string ring, key;

    // Output: 4
    {
        Solution sol;
        ring = "godding", key = "gd";
        // cout << "ring: " << ring << ", key: " << key << " -> " <<
        // sol.findRotateSteps(ring, key) << endl;
    }

    // Output: 13
    {
        Solution sol;
        ring = "godding", key = "godding";
        // cout << "ring: " << ring << ", key: " << key << " -> " <<
        // sol.findRotateSteps(ring, key) << endl;
    }

    // Output: 11
    {
        Solution sol;
        ring = "godding", key = "gdgi";
        // cout << "ring: " << ring << ", key: " << key << " -> " <<
        // sol.findRotateSteps(ring, key) << endl;
    }

    // Output: 13
    {
        Solution sol;
        ring = "ababcab";
        key = "acbaac";
        cout << "ring: " << ring << ", key: " << key << " -> "
             << sol.findRotateSteps(ring, key) << endl;
    }

    // Output: 17
    {
        Solution sol;
        ring = "ababcab";
        key = "acbaacba";
        // cout << "ring: " << ring << ", key: " << key << " -> " <<
        // sol.findRotateSteps(ring, key) << endl;
    }

    return 0;
}
