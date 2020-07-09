/*
1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits
Hard

Given a string num representing the digits of a very large integer and an integer k.
You are allowed to swap any two adjacent digits of the integer at most k times.
Return the minimum integer you can obtain also as a string.

Example 1:
Input: num = "4321", k = 4
Output: "1342"
Explanation: The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.

Example 2:
Input: num = "100", k = 1
Output: "010"
Explanation: It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.

Example 3:
Input: num = "36789", k = 1000
Output: "36789"
Explanation: We can keep the number without any swaps.

Example 4:
Input: num = "22", k = 22
Output: "22"

Example 5:
Input: num = "9438957234785635408", k = 23
Output: "0345989723478563548"

Constraints:
1 <= num.length <= 30000
num contains digits only and doesn't have leading zeros.
1 <= k <= 10^9
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
    int get_pos(vector<int>& nums, int n) {
        int res = -1, sz = nums.size(), lo = 0, hi = sz - 1;
        while (lo <= hi) {
            int mid = (hi+lo) / 2;
            if (nums[mid] < n) {
                res = mid;
                lo = mid + 1;
            } else
            {
                hi = mid - 1;
            }
        }
        return res + 1;
    }
    string minInteger(string& num, int k) {
        vector<vector<int>> pos(10);
        vector<size_t> index(10, 0);
        vector<int> moved;
        ostringstream oss;
        int sz = num.size();
        for (int i = 0; i < sz; ++i)
            pos[num[i] - '0'].push_back(i);
        auto lambda = [&] (int pi, int pj) {
            if (pj < 0)
                return true;
            if (pi < 0)
                return false;
            int i = num[pi] - '0', j = num[pj] - '0';
            int diffi = pi - get_pos(moved, pi);
            int diffj = pj - get_pos(moved, pj);
            return ((i < j && diffi <= k) || (diffj > k && diffi <= diffj));
        };
        vector<int> elems(10, -1);
        int cnt = 0;
        for (int i = 0; i < 10; ++i) {
            if (pos[i].size()) {
                elems[i] = pos[i][0];
                index[i] = 0;
                ++cnt;
            }
        }

        while (cnt > 0) {
            int p = *min_element(begin(elems), end(elems), lambda);
            int i = num[p] - '0';
            int ni = ++index[i];
            if (ni < pos[i].size())
                elems[i] = pos[i][ni];
            else {
                --cnt;
                elems[i] = -1;
            }
            int diff = p - get_pos(moved, p);
            if (diff > k)
                break;
            oss << i;
            num[p] = 'x';
            k -= diff;
            auto it = lower_bound(moved.begin(), moved.end(), p);
            moved.insert(it, p);
        }

        for (int i = 0; i < sz; ++i) {
            char ch = num[i];
            if (ch != 'x')
                oss << ch;
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    string num;
    int k;

    // Output: "1342"
    num = "4321", k = 4;
    cout << sol.minInteger(num, k) << endl;

    // Output: "010"
    num = "100", k = 1;
    cout << sol.minInteger(num, k) << endl;

    // Output: "36789"
    num = "36789", k = 1000;
    cout << sol.minInteger(num, k) << endl;

    // Output: "22"
    num = "22", k = 22;
    cout << sol.minInteger(num, k) << endl;

    // Output: "0345989723478563548"
    num = "9438957234785635408", k = 23;
    cout << sol.minInteger(num, k) << endl;

    // Output: "124498948179"
    num = "294984148179", k = 11;
    cout << sol.minInteger(num, k) << endl;

    // Output: "588597035719081"
    num = "858957035719081", k = 2;
    cout << sol.minInteger(num, k) << endl;

    // Output: "05455649783213206850845"
    num = "55456497803213206850845", k = 10;
    cout << sol.minInteger(num, k) << endl;

    return 0;
}
