/*
1271. Hexspeak
Easy

A decimal number can be converted to its Hexspeak representation by first converting it to an uppercase hexadecimal string, then replacing all occurrences of the digit 0 with the letter O, and the digit 1 with the letter I.  Such a representation is valid if and only if it consists only of the letters in the set {"A", "B", "C", "D", "E", "F", "I", "O"}.

Given a string num representing a decimal integer N, return the Hexspeak representation of N if it is valid, otherwise return "ERROR". 

Example 1:
Input: num = "257"
Output: "IOI"
Explanation: 257 is 101 in hexadecimal.

Example 2:
Input: num = "3"
Output: "ERROR"

Constraints:
1 <= N <= 10^12
There are no leading zeros in the given string.
All answers must be in uppercase letters.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    string toHexspeak(string n) {
        ostringstream oss;
        long long num = stol(n);
        while (num > 0) {
            auto remain = num % 16;
            if (remain == 0)
                oss << 'O';
            else if (remain == 1)
                oss << 'I';
            else if (remain >= 10) {
                char ch = 'A' + remain - 10;
                oss << ch;
            } else
                return "ERROR";
            num /= 16;
        }
        string st = oss.str();
        reverse(begin(st), end(st));
        return st;
    }
};

int main() {
    Solution sol;
    return 0;
}
