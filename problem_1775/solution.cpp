/*
1775. Equal Sum Arrays With Minimum Number of Operations
Medium

You are given two arrays of integers nums1 and nums2, possibly of different lengths.
The values in the arrays are between 1 and 6, inclusive.

In one operation, you can change any integer's value in any of the arrays to any value between 1 and 6, inclusive.

Return the minimum number of operations required to make the sum of values in nums1 equal to the sum of values in nums2.
Return -1 if it is not possible to make the sum of the two arrays equal.


Example 1:
Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
- Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
- Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
- Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].

Example 2:
Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
Output: -1
Explanation: There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make them equal.

Example 3:
Input: nums1 = [6,6], nums2 = [1]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
- Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
- Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
- Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].

Constraints:

1 <= nums1.length, nums2.length <= 10^5
1 <= nums1[i], nums2[i] <= 6
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
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> n1, n2;
        int s1 = 0, s2 = 0, cnt = 0;
        for (int n: nums1) {
            ++n1[n];
            s1 += n;
        }
        for (int n: nums2) {
            ++n2[n];
            s2 += n;
        }

        if (s1 < s2) {
            swap(n1, n2);
            swap(s1, s2);
        }

        while (s1 != s2) {
            ++cnt;
            int diff = s1 - s2;
            int m1 = n1.rbegin()->first, m2 = n2.begin()->first;
            int adj1 = min(m1 - 1, diff), adj2 = min(6 - m2, diff);
            if (adj1 == 0 && adj2 == 0)
                return -1;
            if (adj1 > adj2) {
                ++n1[m1 - adj1];
                s1 -= adj1;
                if (--n1[m1] == 0)
                    n1.erase(m1);
            } else {
                ++n2[m2 + adj2];
                s2 += adj2;
                if (--n2[m2] == 0)
                    n2.erase(m2);
            }
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums1, nums2;

    // Output: 3
    nums1 = {1,2,3,4,5,6}, nums2 = {1,1,2,2,2,2};
    cout << sol.minOperations(nums1, nums2) << endl;

    // Output: -1
    nums1 = {1,1,1,1,1,1,1}, nums2 = {6};
    cout << sol.minOperations(nums1, nums2) << endl;

    // Output: 3
    nums1 = {6,6}, nums2 = {1};
    cout << sol.minOperations(nums1, nums2) << endl;

    return 0;
}
