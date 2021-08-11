/*
954. Array of Doubled Pairs
Medium

Given an array of integers arr of even length, return true if and only if it is possible to reorder it
such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2.

Example 1:
Input: arr = [3,1,3,6]
Output: false

Example 2:
Input: arr = [2,1,2,6]
Output: false

Example 3:
Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].

Example 4:
Input: arr = [1,2,4,16,8,4]
Output: false

Constraints:
0 <= arr.length <= 3 * 10^4
arr.length is even.
-10^5 <= arr[i] <= 10^5
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

#define fisz(n) for(int i = 0; i < n; ++i)

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> nums(begin(arr), end(arr));
        while (nums.size()) {
            int n = *nums.begin();
            nums.erase(nums.begin());
            if (n < 0) {
                if (n & 1)
                    return false;
                n /= 2;
            } else
                n *= 2;
            auto it = nums.find(n);
            if (it == end(nums))
                return false;
            nums.erase(it);
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: false
    arr = {3,1,3,6};
    cout << boolalpha << sol.canReorderDoubled(arr) << endl;

    // Output: false
    arr = {2,1,2,6};
    cout << boolalpha << sol.canReorderDoubled(arr) << endl;

    //Output: true
    arr = {4,-2,2,-4};
    cout << boolalpha << sol.canReorderDoubled(arr) << endl;

    //Output: false
    arr = {1,2,4,16,8,4};
    cout << boolalpha << sol.canReorderDoubled(arr) << endl;

    // Output: false
    arr = {-1,2};
    cout << boolalpha << sol.canReorderDoubled(arr) << endl;

    return 0;
}
