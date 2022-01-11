/*
881. Boats to Save People
Medium

The i-th person has weight people[i], and each boat can carry a maximum weight of limit.
Each boat carries at most 2 people at the same time, provided the sum of the weight of
those people is at most limit.

Return the minimum number of boats to carry every given person. (It is guaranteed
each person can be carried by a boat.)

Example 1:
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Example 2:
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Example 3:
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)

Note:
1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
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
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int, greater<int>> nums (begin(people), end(people));
        copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
        cout << endl;

        int res = 0;
        while (nums.size()) {
            auto it1 = nums.begin();
            int n1 = *it1;
            nums.erase(it1);
            ++res;
            if (nums.empty())
                break;
            auto it2 = nums.lower_bound(limit - n1);
            if (it2 != end(nums))
                nums.erase(it2);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> people;
    int limit;

    // Output: 1
    people = {1,2}, limit = 3;
    cout << sol.numRescueBoats(people, limit) << endl;

    // Output: 3
    people = {3,2,2,1}, limit = 3;
    cout << sol.numRescueBoats(people, limit) << endl;

    // Output: 4
    people = {3,5,3,4}, limit = 5;
    cout << sol.numRescueBoats(people, limit) << endl;

    return 0;
}
