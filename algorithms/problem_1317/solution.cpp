/*
1317. Convert Integer to the Sum of Two No-Zero Integers
Easy

Given an integer n. No-Zero integer is a positive integer which doesn't contain any 0 in its decimal representation.

Return a list of two integers [A, B] where:

A and B are No-Zero integers.
A + B = n
It's guarateed that there is at least one valid solution. If there are many valid solutions you can return any of them.


Example 1:
Input: n = 2
Output: [1,1]
Explanation: A = 1, B = 1. A + B = n and both A and B don't contain any 0 in their decimal representation.

Example 2:
Input: n = 11
Output: [2,9]

Example 3:
Input: n = 10000
Output: [1,9999]

Example 4:
Input: n = 69
Output: [1,68]

Example 5:
Input: n = 1010
Output: [11,999]

Constraints:
2 <= n <= 10^4
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
    bool is_nozero(int num) {
        while (num) {
            if (num % 10 == 0)
                return false;
            num /= 10;
        }
        return true;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for (int i = 1; i <= n /2; ++i) {
            int j = n-i;
            if (is_nozero(i) && is_nozero(j))
                return {i, j};
        }
        return {0, 0};
    }
};

int main() {
    Solution sol;
    return 0;
}
