/*
600. Non-negative Integers without Consecutive Ones
Hard

Given a positive integer n, find the number of non-negative integers less than or equal to n,
whose binary representations do NOT contain consecutive ones.

Example 1:
Input: 5
Output: 5
Explanation: 
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 

Note: 1 <= n <= 10^9
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
    int highest_bit(int num) {
        for (int index = 31; index >= 0; --index) {
            if (num & (1 << index))
                return index;
        }
        return 0;
    }

    unordered_map<int, int> dp;
    
    int findIntegers(int num) {
        if (num < 3)
            return num + 1;
        else if (num == 3)
            return 3;

        auto it = dp.find(num);
        if (it != dp.end())
            return it->second;
        int hi = highest_bit(num);        
        int res = 0;
        if (num & (1 << (hi - 1))) {
            if (hi > 2)
                res = findIntegers((1 << (hi -1)) - 1);
            else
                res = 2;
        } else {
            res = findIntegers(num & ~(1 << hi) & ~(1 << (hi-1)));
        }

        return dp[num] = res + findIntegers((1 << hi) - 1);
    }
};

int main() {
    Solution sol;
    int n;

    // Output: 5
    n = 5;
    cout << n << " -> " << sol.findIntegers(n) << endl;

    // Output: 5
    n = 6;
    cout << n << " -> " << sol.findIntegers(n) << endl;
    
    // Output: 5
    n = 7;
    cout << n << " -> " << sol.findIntegers(n) << endl;
    
    // Output: 6
    n = 8;
    cout << n << " -> " << sol.findIntegers(n) << endl;
    
    // Output: 8
    n = 10;
    cout << n << " -> " << sol.findIntegers(n) << endl;

    // Output: 8
    n = 15;
    cout << n << " -> " << sol.findIntegers(n) << endl;
    
    // Output: 9
    n = 16;
    cout << n << " -> " << sol.findIntegers(n) << endl;

    // Output: 12
    n = 20;
    cout << n << " -> " << sol.findIntegers(n) << endl;

    // Output: 34
    n = 100;
    cout << n << " -> " << sol.findIntegers(n) << endl;

    // Output: 144
    n = 1000;
    cout << n << " -> " << sol.findIntegers(n) << endl;

    // Output:
    n = 10000;
    cout << n << " -> " << sol.findIntegers(n) << endl;
    
    return 0;
}
