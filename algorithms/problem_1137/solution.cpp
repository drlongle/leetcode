/*
1137. N-th Tribonacci Number
Easy

The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
Example 1:
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:
Input: n = 25
Output: 1389537
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> nums{0,1,1};
        int n_size = 3;
        for (int i = n_size; i <= n; ++i) {
            nums[i % n_size] = accumulate(begin(nums), end(nums), 0);
        }
        return nums[n % n_size];
    }
};

int main()
{
    Solution sol;

    cout << "Result: 0 --> " << sol.tribonacci(0) << endl;
    cout << "Result: 1 --> " << sol.tribonacci(1) << endl;
    cout << "Result: 2 --> " << sol.tribonacci(2) << endl;
    cout << "Result: 3 --> " << sol.tribonacci(3) << endl;
    cout << "Result: 4 --> " << sol.tribonacci(4) << endl;
    cout << "Result: 25 --> " << sol.tribonacci(25) << endl;

    return 0;
}

