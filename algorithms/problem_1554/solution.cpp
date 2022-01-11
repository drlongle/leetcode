/*
1554. Strings Differ by One Character
Medium

Given a list of strings dict where all the strings are of the same length.

Return True if there are 2 strings that only differ by 1 character in the same index,
otherwise return False.

Follow up: Could you solve this problem in O(n*m) where n is the length of dict
and m is the length of each string.

Example 1:
Input: dict = ["abcd","acbd", "aacd"]
Output: true
Explanation: Strings "abcd" and "aacd" differ only by one character in the index 1.

Example 2:
Input: dict = ["ab","cd","yz"]
Output: false

Example 3:
Input: dict = ["abcd","cccc","abyd","abab"]
Output: true

Constraints:
Number of characters in dict <= 10^5
dict[i].length == dict[j].length
dict[i] should be unique.
dict[i] contains only lowercase English letters.
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
    bool differByOne(vector<string>& dict) {
        int n = dict[0].size(), sz = dict.size();
        vector<const char*> ptr(sz);
        for(int i=0;i<sz;++i)
            ptr[i]=dict[i].c_str();
        for (int i = 0; i < sz; ++i) {
            for (int j = i+1; j < sz; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (ptr[i][k] != ptr[j][k]) {
                        if (memcmp(ptr[i]+k+1, ptr[j]+k+1, n-k-1)==0) {
                            return true;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<string> dict;

    // Output: true
    dict = {"abcd","acbd", "aacd"};
    cout << boolalpha << sol.differByOne(dict) << endl;

    // Output: false
    dict = {"ab","cd","yz"};
    cout << boolalpha << sol.differByOne(dict) << endl;

    // Output: true
    dict = {"abcd","cccc","abyd","abab"};
    cout << boolalpha << sol.differByOne(dict) << endl;

    return 0;
}
