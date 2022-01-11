/*
1256. Encode Number
Easy

Given a non-negative integer num, Return its encoding string.

The encoding is done by converting the integer to a string using a secret function that you
should deduce from the following table: 

0 -> ""
1 -> "0"
2 -> "1"
3 -> "00"
4 -> "01"
5 -> "10"
6 -> "11"
7 -> "000"

Example 1:

Input: num = 23
Output: "1000"
Example 2:

Input: num = 107
Output: "101100"
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
    string encode(int num) {
        if (!num)
            return "";
        int len = 0;
        while (true) {
            if (num +1 <= (1 << len) -1 )
                break;
            ++len;
        }
        
        ostringstream oss;
        num -= (1 << (len-1)) -1;
        --len;

        for (; len > 0; --len) {
            oss << (num & (1 << (len-1)) ? "1" : "0");
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    int num;

    for (num = 0; num <= 24; ++num)
        cout << num << " -> " << sol.encode(num) << endl;

    num = 107;
    cout << num << " -> " << sol.encode(num) << endl;
    
    return 0;
}
