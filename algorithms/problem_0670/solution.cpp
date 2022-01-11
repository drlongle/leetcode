/*
670. Maximum Swap
Medium

Share
Given a non-negative integer, you could swap two digits at most once to get the maximum
valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 10^8]
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        size_t sz = s.size();
        for (int k = 9; k > 0; --k) {
            char ch = '0' + k;
            size_t i = 0, j = s.find_last_of(ch);
            for (; i < sz; ++i) {
                if (s[i] < ch)
                    break;
            }
            if (j != string::npos && i < j) {
                swap(s[i], s[j]);
                return stoi(s);
            }
        }

        return stoi(s);
    }
};

int main() {
    Solution sol;

    for (int num: {1993, 8813, 2257, 2736, 9936, 0, 1, 10, 102, 1023, 31923, 298})
        cout << num << " -> " << sol.maximumSwap(num) << endl;

    return 0;
}
