/*
825. Friends Of Appropriate Ages
Medium

Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person.
Person A will NOT friend request person B (B != A) if any of the following conditions are true:

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
Otherwise, A will friend request B.

Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.

How many total friend requests are made?

Example 1:
Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.

Example 2:
Input: [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.

Example 3:
Input: [20,30,100,110,120]
Output: 3
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.

Notes:
1 <= ages.length <= 20000.
1 <= ages[i] <= 120.
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

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(begin(ages), end(ages));
        int sz = ages.size(), sum = 0;
        for (int i = 0; i < sz; ++i) {
            int n = ages[i];
            auto it1 = upper_bound(begin(ages), end(ages), 0.5 * n + 7);
            auto it2 = lower_bound(begin(ages), end(ages), n + 1);
            int y = it2 - begin(ages);
            int x = it1 - begin(ages);
            if (y >= x) {
                sum += y - x - (x <= i && i <= y ? 1 : 0);
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> ages;

    // Output: 2
    ages = {16,16};
    cout << sol.numFriendRequests(ages) << endl;

    // Output: 2
    ages = {16,17,18};
    cout << sol.numFriendRequests(ages) << endl;

    // Output: 3
    ages = {20,30,100,110,120};
    cout << sol.numFriendRequests(ages) << endl;

    return 0;
}
