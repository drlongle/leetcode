/*
1521. Find a Value of a Mysterious Function Closest to Target
Hard

Winston was given the above mysterious function func. He has an integer array arr and an integer target
and he wants to find the values l and r that make the value |func(arr, l, r) - target| minimum possible.

// Mysterious function
int func(vector<int>& arr, int l, int r)
{
    if (r < l)
        return -1000000000;
    int ans = arr[l];
    for (int i = 1+1; i <= r; ++i)
        ans = ans & arr[i];
    return ans;
}

Return the minimum possible value of |func(arr, l, r) - target|.

Notice that func should be called with the values l and r where 0 <= l, r < arr.length.

Example 1:
Input: arr = [9,12,3,7,15], target = 5
Output: 2
Explanation: Calling func with all the pairs of [l,r] = [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]], Winston got the following results [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0]. The value closest to 5 is 7 and 3, thus the minimum difference is 2.

Example 2:
Input: arr = [1000000,1000000,1000000], target = 1
Output: 999999
Explanation: Winston called the func with all possible values of [l,r] and he always got 1000000, thus the min difference is 999999.

Example 3:
Input: arr = [1,2,4,8,16], target = 0
Output: 0

Constraints:
1 <= arr.length <= 10^5
1 <= arr[i] <= 10^6
0 <= target <= 10^7
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
    int closestToTarget(vector<int>& arr, int target) {
        int ans = numeric_limits<int>::max(), sz = arr.size();
        vector<int> nums;
        for (int i = 0; i < sz; ++i) {
            if (i == 0 || arr[i] != arr[i-1])
                nums.emplace_back(arr[i]);
        }
        int nz = nums.size();
        for (int i = 0; i < nz; ++i) {
            int a = 0xffffffff;
            for (int j = i; j < nz; ++j) {
                a &= nums[j];
                ans = min(ans, abs(target - a));
                if (a < target)
                    break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int target;

    // Output: 2
    arr = {9,12,3,7,15}, target = 5;
    cout << sol.closestToTarget(arr, target) << endl;

    // Output: 999999
    arr = {1000000,1000000,1000000}, target = 1;
    cout << sol.closestToTarget(arr, target) << endl;

    // Output: 0
    arr = {1,2,4,8,16}, target = 0;
    cout << sol.closestToTarget(arr, target) << endl;

    return 0;
}
