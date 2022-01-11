/*
397. Integer Replacement
Difficulty: Medium

Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int replace(long long n) {
        if (n == 1)
            return 0;
        int res;
        auto it = cache.find(n);
        if (it != cache.cend()) {
            return it->second;
        }
        if ((n & 1) == 0)
            res = 1 + replace(n >> 1);
        else
            res = 1 + min(replace(n-1), replace(n+1));
        cache[n] = res;
        
        return res;
    }
    
    int integerReplacement(int n) {
        return replace(n);
    }
    
    map<int, int> cache;
};

int main(int argc, char** argv) {
    Solution sol;
    int n;

    // Expected: 3
    n = 8;
    
    // Expected: 4
    n = 7;
    
    n = 2147483647;
    
    cout << "Result: " << sol.integerReplacement(n) << endl;

    return 0;
}
