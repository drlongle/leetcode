/*
821. Shortest Distance to a Character
Easy

Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:
Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

Note:
S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
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
    vector<int> shortestToChar(string S, char C) {
        int sz = S.size();
        vector<int> res(sz, numeric_limits<int>::max());
        int curr = -1;
        for (int i = 0; i < sz ; ++i) {
            if (S[i] == C)
                curr = i;
            if (curr >= 0)
                res[i] = min(res[i], abs(i - curr));
        }
        curr = -1;
        for (int i = sz-1; i >= 0 ; --i) {
            if (S[i] == C)
                curr = i;
            if (curr >= 0)
                res[i] = min(res[i], abs(i - curr));
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
