/*
1177. Can Make Palindrome from Substring
Medium

Given a string s, we make queries on substrings of s.

For each query queries[i] = [left, right, k], we may rearrange the substring s[left], ..., s[right],
and then choose up to k of them to replace with any lowercase English letter.

If the substring is possible to be a palindrome string after the operations above,
the result of the query is true. Otherwise, the result is false.

Return an array answer[], where answer[i] is the result of the i-th query queries[i].

Note that: Each letter is counted individually for replacement so if for example s[left..right] = "aaa",
and k = 2, we can only replace two of the letters. (Also, note that the initial string s is never modified by any query.)

Example :
Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
Output: [true,false,false,true,true]
Explanation:
queries[0] : substring = "d", is palidrome.
queries[1] : substring = "bc", is not palidrome.
queries[2] : substring = "abcd", is not palidrome after replacing only 1 character.
queries[3] : substring = "abcd", could be changed to "abba" which is palidrome. Also
             this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
queries[4] : substring = "abcda", could be changed to "abcba" which is palidrome.
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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries)
    {
        vector<bool> res;

        for (auto& q : queries) {
            map<char, int> counts;
            int odd = 0;
            if (q[2] >= 13) {
                res.emplace_back(true);
                continue;
            }

            for (int i = q[0]; i <= q[1]; ++i) {
                if (++counts[s[i]] % 2 == 1)
                    ++odd;
                else
                    --odd;
            }
            bool palin = odd <= 1 + 2 * q[2];
            res.emplace_back(palin);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> queries;
    string s;

    s = "abcda", queries = {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};

    auto res = sol.canMakePaliQueries(s, queries);
    copy(begin(res), end(res), ostream_iterator<bool>(cout, ", "));
    cout << endl;

    return 0;
}
