/*
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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

#include <string.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> cache(n+1, 0);
        cache[0] = 1;
        cache[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j)
                cache[i] += cache[j-1] * cache[i-j];
        }
        return cache[n];
    }
};

int main()
{
    Solution sol;
    int n;
    n = 2;
    cout << n << " --> " << sol.numTrees(n) << endl;
    return 0;
}
