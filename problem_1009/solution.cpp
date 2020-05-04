/*
1009. Complement of Base 10 Integer
Easy

Every non-negative integer N has a binary representation.  For example, 5 can be represented as "101" in binary, 11 as "1011" in binary, and so on.  Note that except for N = 0, there are no leading zeroes in any binary representation.

The complement of a binary representation is the number in binary you get when changing every 1 to a 0 and 0 to a 1.  For example, the complement of "101" in binary is "010" in binary.

For a given number N in base-10, return the complement of it's binary representation as a base-10 integer.

Example 1:
Input: 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

Example 2:
Input: 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.

Example 3:
Input: 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.

Note:
0 <= N < 10^9
This question is the same as 476: https://leetcode.com/problems/number-complement/
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
    int bitwiseComplement(int num) {
        if (num == 0)
  	    return 1;
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
    int num;

    num = 5;
    cout << sol.bitwiseComplement(num) << endl;

    num = 7;
    cout << sol.bitwiseComplement(num) << endl;

    num = 10;
    cout << sol.bitwiseComplement(num) << endl;

    num = 0;
    cout << sol.bitwiseComplement(num) << endl;
    
    return 0;
}
