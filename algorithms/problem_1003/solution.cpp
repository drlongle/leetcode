/*
1003. Check If Word Is Valid After Substitutions
Difficulty: Medium

We are given that the string "abc" is valid.

From any valid string V, we may split V into two pieces X and Y such that X + Y (X concatenated with Y) is equal to V.  (X or Y may be empty.)  Then, X + "abc" + Y is also valid.

If for example S = "abc", then examples of valid strings are: "abc", "aabcbc", "abcabc", "abcabcababcc".  Examples of invalid strings are: "abccba", "ab", "cababc", "bac".

Return true if and only if the given string S is valid.

Example 1:
Input: "aabcbc"
Output: true
Explanation: 
We start with the valid string "abc".
Then we can insert another "abc" between "a" and "bc", resulting in "a" + "abc" + "bc" which is "aabcbc".

Example 2:
Input: "abcabcababcc"
Output: true
Explanation: 
"abcabcabc" is valid after consecutive insertings of "abc".
Then we can insert "abc" before the last letter, resulting in "abcabcab" + "abc" + "c" which is "abcabcababcc".

Example 3:
Input: "abccba"
Output: false

Example 4:
Input: "cababc"
Output: false
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 3)
            return false;
        vector<char> st;
        for (char ch: s) {
            st.push_back(ch);
            auto ssize = st.size();
            if (ssize >= 3) {
                if (st[ssize-3] == 'a' && st[ssize-2] == 'b' && st[ssize-1] == 'c') {
                    for (int i = 0; i < 3; ++i)
                        st.pop_back();
                }
            }
        }

        /*
        cout << "Remain: ";
        copy(begin(st), end(st), ostream_iterator<char>(cout, ""));
        cout << endl;
        */

        return st.empty();
    }
};

int main() {
    Solution sol;
    string s;

    // Expected: true
    s = "aabcbc";

    // Expected: true
    //s = "abcabcababcc";

    // Expected: false
    //s = "abccba";

    // Expected: false
    //s = "cababc";

    cout << "Result: " << sol.isValid(s) << endl;

    return 0;
}

