/*
1846. Maximum Element After Decreasing and Rearranging
Medium

You are given an array of positive integers arr. Perform some operations (possibly none) on arr so that it satisfies these conditions:
- The value of the first element in arr must be 1.
- The absolute difference between any 2 adjacent elements must be less than or equal to 1. In other words,
 abs(arr[i] - arr[i - 1]) <= 1 for each i where 1 <= i < arr.length (0-indexed). abs(x) is the absolute value of x.

There are 2 types of operations that you can perform any number of times:
- Decrease the value of any element of arr to a smaller positive integer.
- Rearrange the elements of arr to be in any order.

Return the maximum possible value of an element in arr after performing the operations to satisfy the conditions.

Example 1:
Input: arr = [2,2,1,2,1]
Output: 2
Explanation:
We can satisfy the conditions by rearranging arr so it becomes [1,2,2,2,1].
The largest element in arr is 2.

Example 2:
Input: arr = [100,1,1000]
Output: 3
Explanation:
One possible way to satisfy the conditions is by doing the following:
1. Rearrange arr so it becomes [1,100,1000].
2. Decrease the value of the second element to 2.
3. Decrease the value of the third element to 3.
Now arr = [1,2,3], which satisfies the conditions.
The largest element in arr is 3.

Example 3:
Input: arr = [1,2,3,4,5]
Output: 5
Explanation: The array already satisfies the conditions, and the largest element is 5.

Constraints:
1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size(), res = 1;
        sort(begin(arr), end(arr));
        arr[0] = 1;
        for (int i = 1; i < n; ++i) {
            arr[i] = min(arr[i], arr[i-1] + 1);
            res = max(res, arr[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: 2
    arr = {2,2,1,2,1};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr) << endl;

    // Output: 3
    arr = {100,1,1000};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr) << endl;

    // Output: 5
    arr = {1,2,3,4,5};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr) << endl;

    return 0;
}
