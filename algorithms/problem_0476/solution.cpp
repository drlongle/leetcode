/*
476. Number Complement
Easy

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.


Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
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

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int findComplement(int num) {
        ostringstream oss;
        while (num) {
            oss << num % 2;
            num /= 2;
        }
        string s = oss.str();
        reverse(begin(s), end(s));
        int res = 0;

        for (char ch: s) {
            res = res * 2 + ('1' - ch);
        }
        
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
