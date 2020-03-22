/*
1390. Four Divisors
Medium

Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

If there is no such integer in the array, return 0.

Example 1:
Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.

Constraints:
1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5
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
    static constexpr int max_num = 100001;
    using BS = bitset<max_num>;
    unordered_map<int, pair<BS, int>> dp;
    
    pair<BS, int> get_divisors(int num) {
        auto it = dp.find(num);
        if (it != dp.end()) {
            return it->second;
        }
        pair<BS, int> res;
        res.first.set(1);
        res.second++;
        res.first.set(num);
        res.second += num;
        int lim = sqrt(num);
        for (int i = 2; i <= lim; ++i) {
            if (num % i == 0) {
                res.first.set(i);
                res.second += i;
                int div = num / i;
                auto temp = get_divisors(div);
                res.first |= temp.first;
                res.second += div;
                if (res.first.count() > 4)
                    break;
            }
        }
        return dp[num] = res;
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (auto n: nums) {
            auto res = get_divisors(n);

            if (res.first.count() == 4) {
                sum += res.second;
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {21,4,7};
    cout << sol.sumFourDivisors(nums) << endl;
    
    return 0;
}
