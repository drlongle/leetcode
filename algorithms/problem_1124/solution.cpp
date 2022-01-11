/*
1124. Longest Well-Performing Interval
Medium

We are given hours, a list of the number of hours worked per day for
a given employee. A day is considered to be a tiring day if and only
if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number
of tiring days is strictly larger than the number of non-tiring days.
Return the length of the longest well-performing interval.

Example 1:
Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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

struct Entry {
    Entry(int s, int p): sum(s), pos(p) {}
    int sum, pos;
};

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0, sum = 0;
        int len = hours.size();

        vector<Entry> sums{{0, 0}};
        for (int i = 1; i <= len; ++i) {
            sum += (hours[i-1] > 8) ? 1 : -1;
            for (size_t j = 0; j < sums.size(); ++j) {
                if (sum > sums[j].sum)
                    res = max(res, i-sums[j].pos);
            }
            if (sum < sums.back().sum)
                sums.emplace_back(sum, i);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> hours;

    // Expected: 3
    hours = {9,9,6,0,6,6,9};

    // Expected: 3
    hours = {9,6,9};

    // Expected: 3
    hours = {6,9,9};

    // 60 / 98 test cases passed
    // Expected: 6
    hours = {6,10,8,10,11,11};

    // 64 / 98 test cases passed.
    // Expected: 3
    hours = {9,9,6,0,6,6,9};

    cout << "Result: " << sol.longestWPI(hours) << endl;

    return 0;
}

