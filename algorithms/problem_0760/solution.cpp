/*
760. Find Anagram Mappings
Easy

Given two lists nums1 and nums2, and nums2 is an anagram of nums1. nums2 is an anagram of nums1 means
nums2 is made by randomizing the order of the elements in nums1.

We want to find an index mapping mapping, from nums1 to nums2. A mapping mapping[i] = j means
the i-th element in nums1 appears in nums2 at index j.

These lists nums1 and nums2 may contain duplicates. If there are multiple answers, output any of them.

For example, given
nums1 = [12, 28, 46, 32, 50]
nums2 = [50, 12, 32, 46, 28]

We should return [1, 4, 3, 2, 0]
as mapping[0] = 1 because the 0th element of nums1 appears at nums2[1],
 and mapping[1] = 4 because the 1st element of nums1 appears at nums2[4], and so on.

Note:
nums1, nums2 have equal lengths in range [1, 100].
nums1[i], nums2[i] are integers in range [0, 10^5].
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
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> table;
        int n = B.size();
        for (int i = 0; i < n; ++i)
            table[B[i]] = i;
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = table[A[i]];
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
