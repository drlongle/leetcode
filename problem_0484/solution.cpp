/*
484. Find Permutation
Medium

A permutation perm of n integers of all the integers in the range [1, n] can be represented as a string s
of length n - 1 where:

s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].

Given a string s, reconstruct the lexicographically smallest permutation perm and return it.

Example 1:
Input: s = "I"
Output: [1,2]
Explanation: [1,2] is the only legal permutation that can represented by s,
where the number 1 and 2 construct an increasing relationship.

Example 2:

Input: s = "DI"
Output: [2,1,3]
Explanation: Both [2,1,3] and [3,1,2] can be represented as "DI", but since we want to find
the smallest lexicographical permutation, you should return [2,1,3]

Constraints:
1 <= s.length <= 10^5
s[i] is either 'I' or 'D'.
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
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> res(n + 1);
        iota(begin(res), end(res), 1);
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'I')
                continue;
            int j = i;
            while (j - 1 >= 0 && s[j - 1] == 'D')
                --j;
            reverse(begin(res) + j, begin(res) + i + 2);
            i = j;
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
