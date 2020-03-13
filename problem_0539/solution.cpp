/*
539. Minimum Time Difference
Medium

Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
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
#include <memory>
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
    struct Compare {
        bool operator()(const string& s1, const string& s2) const {
            int h1 = stoi(s1.substr(0, 2));
            int h2 = stoi(s2.substr(0, 2));
            int m1 = stoi(s1.substr(3));
            int m2 = stoi(s2.substr(3));
            return h1 < h2 || (h1 == h2 && m1 < m2);
        }
    };
    int diff(string& s1, string& s2) {
        int h1 = stoi(s1.substr(0, 2));
        int h2 = stoi(s2.substr(0, 2));
        int m1 = stoi(s1.substr(3));
        int m2 = stoi(s2.substr(3));
        int diff = (h2 - h1) * 60 + (m2 - m1);

        return min(diff, 24 * 60 - diff);
    }
    
    int findMinDifference(vector<string>& timePoints) {
        sort(begin(timePoints), end(timePoints), Compare());
        int res = diff(timePoints[0], timePoints.back());
        for (size_t i = 0; i < timePoints.size() - 1; ++i) {
            res = min(res, diff(timePoints[i], timePoints[i+1]));
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> timePoints;

    // Output: 1
    timePoints = {"23:59","00:00"};
    cout << sol.findMinDifference(timePoints) << endl;

    return 0;
}
