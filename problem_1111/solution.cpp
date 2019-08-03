/*
1111. Maximum Nesting Depth of Two Valid Parentheses Strings
Medium

A string is a valid parentheses string (denoted VPS) if and only if it consists
of "(" and ")" characters only, and:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.

We can similarly define the nesting depth depth(S) of any VPS S as follows:
depth("") = 0
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.

For example,  "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2),
and ")(" and "(()" are not VPS's.

Given a VPS seq, split it into two disjoint subsequences A and B, such that A and B
are VPS's (and A.length + B.length = seq.length).

Now choose any such A and B such that max(depth(A), depth(B)) is the minimum possible value.
Return an answer array (of length seq.length) that encodes such a choice of A and B:
answer[i] = 0 if seq[i] is part of A, else answer[i] = 1. Note that even though multiple
answers may exist, you may return any of them.

Example 1:
Input: seq = "(()())"
Output: [0,1,1,1,1,0]

Example 2:
Input: seq = "()(())()"
Output: [0,0,0,1,1,0,1,1]
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
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> res;
        vector<stack<int>> runs(2);
        stack<int> s;
        for (auto ch : seq) {
            if (ch == '(') {
                auto it = min_element(begin(runs), end(runs),
                        [](const stack<int>& s1, const stack<int>& s2) { return s1.size() < s2.size(); });
                int index = distance(begin(runs), it);
                runs[index].push(index);
                s.emplace(index);
                res.emplace_back(index);
            } else {
                int index = s.top();
                res.emplace_back(index);
                s.pop();
                runs[index].pop();
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    string seq;

    // Expected: [0,1,1,1,1,0]
    seq = "(()())";

    // Expected: [0,0,0,1,1,0,1,1]
    // seq = "()(())()";

    vector<int> res = sol.maxDepthAfterSplit(seq);

    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
