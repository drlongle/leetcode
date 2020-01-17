/*
1209. Remove All Adjacent Duplicates in String II
Medium

Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

Example 1:
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Example 2:
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Example 3:
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"

Constraints:
1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
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
    string removeDuplicates(string s, int k) {
        string t = s;
        int wid = 0, cnt, sz = s.size();
        char curr = -1;
        for (int i = 0; i < sz; ++i) {
            if (s[i] != curr) {
                curr = s[i];
                cnt = 1;
            } else
                ++cnt;
            if (cnt == k) {
                wid -= k - 1;
                if (wid == 0) {
                    curr = -1;
                } else {
                    curr = t[wid-1];
                    cnt = 1;
                    for (int j = wid-2; j >= 0; --j) {
                        if (t[j] != curr)
                            break;
                        ++cnt;
                    }
                }
            } else
                t[wid++] = curr;
        }

        return t.substr(0, wid);
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    // Output: "abcd"
    s = "abcd", k = 2;

    // Output: "aa"
    //s = "deeedbbcccbdaa", k = 3;

    // Output: "ps"
    s = "pbbcggttciiippooaais", k = 2;

    cout << "Result: " << sol.removeDuplicates(s, k) << endl;
    
    return 0;
}
