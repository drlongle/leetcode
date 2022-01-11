/*
1215. Stepping Numbers
Medium

A Stepping Number is an integer such that all of its adjacent digits have an absolute
difference of exactly 1. For example, 321 is a Stepping Number while 421 is not.

Given two integers low and high, find and return a sorted list of all the
Stepping Numbers in the range [low, high] inclusive.

Example:
Input: low = 0, high = 21
Output: [0,1,2,3,4,5,6,7,8,9,10,12,21]
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

map<pair<int,int>, vector<int>> cache;

vector<int> getSteppingNumbers(int digit, int nr_digits) {
    vector<int> ans;
    if (nr_digits == 1)
        return vector<int>{digit};
    auto it = cache.find({digit, nr_digits});
    if (it != cache.end())
        return it->second;
    if (digit >= 1)  {
        auto arr = getSteppingNumbers(digit-1, nr_digits - 1);
        for (auto n: arr)
            ans.emplace_back(digit*pow(10, nr_digits-1) + n);
    }
    if (digit < 9) {
        auto arr = getSteppingNumbers(digit+1, nr_digits - 1);
        for (auto n: arr)
            ans.emplace_back(digit*pow(10, nr_digits-1) + n);
    }
    cache[{digit, nr_digits}] = ans;

    return ans;
}

class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        cache.clear();
        string slow = to_string(low);
        string shigh = to_string(high);
        int llen = slow.size();
        int hlen = shigh.size();
        for (int len = llen, lead = slow[0] - '0'; len <= hlen;) {
            auto res = getSteppingNumbers(lead, len);
            for (auto r: res)
                if (r >= low && r <= high)
                    ans.emplace_back(r);
            if (++lead > 9) {
                lead = 1;
                ++len;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    int low, high;

    // Output: [0,1,2,3,4,5,6,7,8,9,10,12,21]
    low = 0, high = 21;

    //
    low = 0, high = 1000000000;
    
    auto res = sol.countSteppingNumbers(low, high);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
