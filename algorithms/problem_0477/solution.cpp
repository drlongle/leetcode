/*
477. Total Hamming Distance
Medium

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
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
    int totalHammingDistance(vector<int>& nums) {
        int sz = nums.size(), res = 0;
        vector<int> cnt(32, 0);
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < 32; ++j) {
                if (nums[i] & (1 << j)) {
                    res += (i - cnt[j]);
                    ++cnt[j];
                } else {
                    res += cnt[j];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    
    nums = {4,14,2};
    cout << sol.totalHammingDistance(nums) << endl;

    nums = {4,14,4};
    cout << sol.totalHammingDistance(nums) << endl;
    
    return 0;
}
