/*
1482. Minimum Number of Days to Make m Bouquets
Difficulty: Medium

Given an integer array bloomDay, an integer m and an integer k.

We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

Example 1:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

Example 2:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.

Example 3:
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here's the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.

Example 4:
Input: bloomDay = [1000000000,1000000000], m = 1, k = 1
Output: 1000000000
Explanation: You need to wait 1000000000 days to have a flower ready for a bouquet.

Example 5:
Input: bloomDay = [1,10,2,9,3,8,4,7,5,6], m = 4, k = 2
Output: 9

Constraints:
bloomDay.length == n
1 <= n <= 10^5
1 <= bloomDay[i] <= 10^9
1 <= m <= 10^6
1 <= k <= n
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int thres) {
        int begin = 0, end, sz = bloomDay.size(), cnt = 0;
        while (begin < sz) {
            end = begin;
            bool success = false;
            while (begin < sz && bloomDay[begin] <= thres) {
                ++begin;
                if (begin - end >= k) {
                    ++cnt;
                    success = true;
                    break;
                }
            }
            if (!success)
                ++begin;
        }
        return cnt >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int flowers = m * k, n = bloomDay.size();
        if (flowers > n)
            return -1;
        vector<int> day(bloomDay);
        sort(begin(day), end(day));
        auto last = unique(begin(day), end(day));
        day.erase(last, day.end());
        int sid = 0, eid = day.size() - 1;
        int res = -1;
        while (sid <= eid) {
            int mid = (sid + eid) / 2;
            if (check(bloomDay, m, k, day[mid])) {
                res = day[mid];
                eid = mid - 1;
            } else
                sid = mid + 1;
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> bloomDay;
    int m, k;

    // Output: 3
    bloomDay = {1,10,3,10,2}, m = 3, k = 1;
    cout << sol.minDays(bloomDay, m, k) << endl;

    // Output: -1
    bloomDay = {1,10,3,10,2}, m = 3, k = 2;
    cout << sol.minDays(bloomDay, m, k) << endl;

    // Output: 12
    bloomDay = {7,7,7,7,12,7,7}, m = 2, k = 3;
    cout << sol.minDays(bloomDay, m, k) << endl;

    // Output: 1000000000
    bloomDay = {1000000000,1000000000}, m = 1, k = 1;
    cout << sol.minDays(bloomDay, m, k) << endl;
    
    // Output: 9
    bloomDay = {1,10,2,9,3,8,4,7,5,6}, m = 4, k = 2;
    cout << sol.minDays(bloomDay, m, k) << endl;

    return 0;
}
