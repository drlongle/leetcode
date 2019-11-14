/*
1238. Circular Permutation in Binary Representation
Medium

Given 2 integers n and start. Your task is return any
permutation p of (0,1,2.....,2^n -1) such that :

p[0] = start
p[i] and p[i+1] differ by only one bit in their binary representation.
p[0] and p[2^n -1] must also differ by only one bit in their binary representation.

Example 1:
Input: n = 2, start = 3
Output: [3,2,0,1]
Explanation: The binary representation of the permutation is (11,10,00,01). 
All the adjacent element differ by one bit. Another valid permutation is [3,1,0,2]

Example 2:
Input: n = 3, start = 2
Output: [2,6,7,5,4,0,1,3]
Explanation: The binary representation of the permutation is (010,110,111,101,100,000,001,011).
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

    vector<int> grayCode(int n) {
        vector<int> res = {0, 1};
        for (int i = 2; i <= n; ++i) {
            int idx = res.size() - 1;
            while (idx >= 0) {
                res.emplace_back(res[idx] | 1 << (i - 1));
                --idx;
            }
        }
        return res;
    }
    
    vector<int> circularPermutation(int n, int start) {
        vector<int> res = grayCode(n);
        int idx = 0, sz = res.size();
        while (idx < sz) {
            if (res[idx] == start)
                break;
            ++idx;
        }
        if (idx > 0) {
            reverse(begin(res), begin(res) + idx);
            reverse(begin(res) + idx, end(res));
            reverse(begin(res), end(res));
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    int n, start;

    // Output: [3,2,0,1]
    n = 2, start = 3;

    // Output: [2,6,7,5,4,0,1,3]
    //n = 3, start = 2;

    auto res = sol.circularPermutation(n, start);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
