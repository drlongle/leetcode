/*
594. Longest Harmonious Subsequence
Easy

We define a harmounious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Note: The length of the input array will not exceed 20,000.
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
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> counters;
        for (int num: nums)
            ++counters[num];
        int res = 0;
        for (auto& [val, cnt]: counters) {
            auto it = counters.find(val-1);
            if (it != counters.end())
                res = max(res, cnt + it->second) ;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    
    nums = {1,3,2,2,5,2,3,7};
    cout << sol.findLHS(nums) << endl;

    nums = {1,1,1,1,1,1,1,1};
    cout << sol.findLHS(nums) << endl;
    
    return 0;
}
