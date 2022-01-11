/*
461. Hamming Distance
Easy

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
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

constexpr int num_bits = 32;

class Solution {
public:
    int hammingDistance(int x, int y)
    {
        stringstream ss;
        ss << bitset<32>(x);
        string sx = ss.str();

        ss.str("");
        ss << bitset<32>(y);
        string sy = ss.str();

        int res = 0;
        for (int i = 0; i < num_bits; ++i) {
            if (sx[i] != sy[i])
                ++res;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int x, y;

    // Expected: 3
    x = 3, y = 4;

    // Expected: 2
    // x = 1, y = 4;

    cout << "Result: " << sol.hammingDistance(x, y) << endl;

    return 0;
}
