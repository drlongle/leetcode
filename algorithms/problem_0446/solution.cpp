/*
446. Arithmetic Slices II - Subsequence

    User Accepted: 37
    User Tried: 266
    Total Accepted: 39
    Total Submissions: 1168
    Difficulty: Hard

A sequence of numbers is called arithmetic if it consists of at least three
elements and if the difference between any two consecutive elements is the
same. For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A subsequence slice
of that array is any sequence of integers (P0, P1, ..., Pk) such that
0 <= P0 < P1 < ... < Pk < N.

A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the
sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this
means that k >= 2. The function should return the number of arithmetic
subsequence slices in the array A.

The input contains N integers. Every integer is in the range of -2^31 and
2^31-1 and 0 <= N <= 1000. The output is guaranteed to be less than 2^31-1.

Example:

Input: [2, 4, 6, 8, 10]

Output: 7

Explanation:
All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
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
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0; 
        int temp, nsize = nums.size();
        vector<unordered_map<ll, int>> runs(nsize);
        unordered_map<ll,int>::iterator it;
        for (int i = 1; i < nsize; ++i)
        {
            ll num_i = nums[i];
            for (int j = 0; j < i; ++j)
            {
                ll diff = num_i - nums[j];
                it = runs[j].find(diff);
                if (it != runs[j].end())
                {
                    temp = 1 + it->second;
                    if (temp >= 2)
                        res += temp-1;
                }
                else
                    temp = 1;
                runs[i][diff] += temp;
            }
        }
        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<int> nums;

    nums = {2,4,6,8,10};
    cout << "Result: " << sol.numberOfArithmeticSlices(nums) << endl;

    return 0;
}

