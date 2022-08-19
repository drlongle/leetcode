/*
659. Split Array into Consecutive Subsequences
Medium

Given an array nums sorted in ascending order, return true if and only if you can split it into 1 or more subsequences such that each subsequence consists of consecutive integers and has length at least 3.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5

Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5

Example 3:
Input: [1,2,3,4,4,5]
Output: False

Constraints:
1 <= nums.length <= 10000
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
    bool isPossible(vector<int>& nums) {
        list<int> streaks;
        int n = nums.size(), head = 0, prev;

        while (head < n) {
            int curr = nums[head], cnt = 0;
            while (head < n && nums[head] == curr) {
                ++head, ++cnt;
            }

            for (auto it = streaks.begin(); it != streaks.end();) {
                if (curr != prev + 1 || cnt <= 0) {
                    if (prev - *it < 2)
                        return false;
                    else
                        it = streaks.erase(it);
                } else {
                    ++it;
                    --cnt;
                }
            }

            while (cnt-- > 0) {
                streaks.push_front(curr);
            }
            prev = curr;
        }

        for (auto it = streaks.begin(); it != streaks.end(); ++it) {
            if (prev - *it < 2)
                return false;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: True
    nums = {1,2,3,3,4,5};
    cout << boolalpha << sol.isPossible(nums) << endl;
    
    // Output: True
    nums =  {1,2,3,3,4,4,5,5};
    cout << boolalpha << sol.isPossible(nums) << endl;
    
    // Output: False
    nums = {1,2,3,4,4,5};
    cout << boolalpha << sol.isPossible(nums) << endl;

    // Output: True
    nums = {1, 2, 3, 5, 6, 7};
    cout << boolalpha << sol.isPossible(nums) << endl;

    // Output: False
    nums = {1, 2, 3, 5, 5, 6, 7};
    cout << boolalpha << sol.isPossible(nums) << endl;

    return 0;
}
