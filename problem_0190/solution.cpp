/*
190. Reverse Bits  
Total Accepted: 62002 Total Submissions: 211714 Difficulty: Easy

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it? 
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

void swap_bits(uint32_t& n, int i, int j)
{
    if (((n >> i) & 0x1) != ((n >> j) & 0x1)) {
        n ^= (1 << i) | (1 << j);
    }
}

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int low = 0, high = 31;
        while (low < high) {
            swap_bits(n, low, high);
            ++low,
            --high;
        }
        return n;
    }
};

int main()
{
    Solution sol;
    int n;
    n = 1;
    cout << "Result: " << sol.reverseBits(n) << endl;

    return 0;
}

