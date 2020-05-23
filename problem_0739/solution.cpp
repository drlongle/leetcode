/*
739. Daily Temperatures
Medium

Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
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

#define ll long long
#define ull unsigned long long

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        map<int, int> pos;
        int n = T.size();
        constexpr int max_temp = 100;
        vector<int> days(n);
        for (int i = n-1; i >= 0; --i) {
            int t = T[i];
            auto it = pos.upper_bound(t);
            if (it == pos.end()) {
                days[i] = 0;
            } else {
                int d = it->second;
                for (int j = it->first + 1; j <= max_temp; ++j) {
                    it = pos.find(j);
                    if (it != pos.end())
                        d = min(d, it->second);
                }
                days[i] = d - i;
            }
            pos[t] = i;
        }

        return days;
    }
};

int main() {
    Solution sol;
    vector<int> T, res;

    // your output should be [1, 1, 4, 2, 1, 1, 0, 0].
    T = {73, 74, 75, 71, 69, 72, 76, 73};
    res = sol.dailyTemperatures(T);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
