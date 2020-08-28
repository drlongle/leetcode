/*
1558. Minimum Numbers of Function Calls to Make Target Array
Medium

Given the following code

 func modify(arr, op, idx)
 {
   if (op == 0) {
     arr[idx] = add[idx] + 1
   }
   if (op == 1) {
     for (i = 0; i < arr.length; ++i) {
       arr[i] = arr[i] * 2
     }
   }
 }
Your task is to form an integer array nums from an initial array of zeros arr that is the same size as nums.

Return the minimum number of function calls to make nums from arr.

The answer is guaranteed to fit in a 32-bit signed integer.

Example 1:
Input: nums = [1,5]
Output: 5
Explanation: Increment by 1 (second element): [0, 0] to get [0, 1] (1 operation).
Double all the elements: [0, 1] -> [0, 2] -> [0, 4] (2 operations).
Increment by 1 (both elements)  [0, 4] -> [1, 4] -> [1, 5] (2 operations).
Total of operations: 1 + 2 + 2 = 5.

Example 2:
Input: nums = [2,2]
Output: 3
Explanation: Increment by 1 (both elements) [0, 0] -> [0, 1] -> [1, 1] (2 operations).
Double all the elements: [1, 1] -> [2, 2] (1 operation).
Total of operations: 2 + 1 = 3.

Example 3:
Input: nums = [4,2,5]
Output: 6
Explanation: (initial)[0,0,0] -> [1,0,0] -> [1,0,1] -> [2,0,2] -> [2,1,2] -> [4,2,4] -> [4,2,5](nums).

Example 4:
Input: nums = [3,2,2,4]
Output: 7

Example 5:
Input: nums = [2,4,8,16]
Output: 8

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
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
#include <regex>
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

    int minOperations(vector<int>& nums) {
        int res = 0, sz = nums.size(), zeroes = count(begin(nums), end(nums), 0);
        while (zeroes < sz) {
            for (int& n: nums) {
                if (n == 1) {
                    n = 0;
                    ++zeroes;
                    ++res;
                } else if (n % 2 == 1) {
                    --n;
                    ++res;
                }
            }
            if (zeroes == sz)
                break;
            ++res;
            for (int& n: nums) {
                n /= 2;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1,5};
    cout << sol.minOperations(nums) << endl;

    nums = {2,2};
    cout << sol.minOperations(nums) << endl;

    nums = {4,2,5};
    cout << sol.minOperations(nums) << endl;

    nums = {3,2,2,4};
    cout << sol.minOperations(nums) << endl;

    nums = {2,4,8,16};
    cout << sol.minOperations(nums) << endl;

    return 0;
}
