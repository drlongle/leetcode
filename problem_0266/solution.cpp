/*
266. Palindrome Permutation
Easy

Given a string, determine if a permutation of the string could form a palindrome.

Example 1:
Input: "code"
Output: false

Example 2:
Input: "aab"
Output: true

Example 3:
Input: "carerac"
Output: true
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
    bool canPermutePalindrome(string s) {
        unordered_map<int, int> cnt;
        int odd = 0;
        for (char ch: s) {
            if (++cnt[ch] % 2 == 0)
                --odd;
            else
                ++odd;
        }
        return odd <= 1;
    }
};

int main() {
    Solution sol;

    return 0;
}
