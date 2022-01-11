/*
246. Strobogrammatic Number
Easy

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:
Input: num = "69"
Output: true

Example 2:
Input: num = "88"
Output: true

Example 3:
Input: num = "962"
Output: false

Example 4:
Input: num = "1"
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
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> strbos {
            {'0','0' },
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}};
        string r;
        for (char ch: num) {
            auto it = strbos.find(ch);
            if (it == strbos.end())
                return false;
            r.push_back(it->second);
        }
        reverse(begin(r), end(r));

        return r == num;
    }
};

int main() {
    Solution sol;
    string num;

    num = "69";
    cout << boolalpha << sol.isStrobogrammatic(num) << endl;

    num = "88";
    cout << boolalpha << sol.isStrobogrammatic(num) << endl;

    return 0;
}
