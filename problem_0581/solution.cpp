/*
581. Shortest Unsorted Continuous Subarray
Medium

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
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
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> entries;
        for (int i = 0; i < n; ++i) {
            entries.emplace_back(i, nums[i]);
        }

        stable_sort(begin(entries), end(entries), [] (auto& e1, auto& e2) {return e1.second < e2.second;});
        int start_index = -1, end_index = -1;
        for (int i = 0; i < n && start_index < 0; ++i) {
            if (entries[i].first != i)
                start_index = i;
        }
        for (int i = n-1; i >= 0 && end_index < 0; --i) {
            if (entries[i].first != i)
                end_index = i;
        }
        return start_index < 0 ? 0 : end_index - start_index + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    
    nums =  {2, 6, 4, 8, 10, 9, 15};
    //cout << sol.findUnsortedSubarray(nums) << endl;

    nums =  {1, 2, 3, 4};
    //cout << sol.findUnsortedSubarray(nums) << endl;

    nums = {1,2,3,3,3};
    cout << sol.findUnsortedSubarray(nums) << endl;
    
    return 0;
}
