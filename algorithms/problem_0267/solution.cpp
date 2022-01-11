/*
267. Palindrome Permutation II
Medium

Given a string s, return all the palindromic permutations (without duplicates) of it.

You may return the answer in any order. If s has no palindromic permutation, return an empty list.

Example 1:
Input: s = "aabb"
Output: ["abba","baab"]

Example 2:
Input: s = "abc"
Output: []

Constraints:
1 <= s.length <= 16
s consists of only lowercase English letters.
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
    vector <int> cnt;
    vector<string> res;

    void create (string& s, int i, int j){
        if (i > j)
            res.emplace_back(s);
        int need = 1+(i < j);
        for (int k=0; k<26; ++k){
            if(cnt[k] >= need){
                cnt[k] -= need;
                s[i] = s[j] = 'a'+k;
                create(s,i+1,j-1);
                cnt[k]+=need;
            }
        }
    }

    vector<string> generatePalindromes(string s) {
        cnt.resize(26, 0);
        for (char c: s)
            ++cnt[c-'a'];
        create(s, 0, s.size()-1);
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
