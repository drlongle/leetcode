/*
880. Decoded String at Index
Medium

An encoded string S is given. To find and write the decoded string to a tape, the encoded string is read one
character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.
Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.

Example 1:
Input: S = "leet2code3", K = 10
Output: "o"
Explanation:
The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".

Example 2:
Input: S = "ha22", K = 5
Output: "h"
Explanation:
The decoded string is "hahahaha".  The 5th letter is "h".

Example 3:
Input: S = "a2345678999999999999999", K = 1
Output: "a"
Explanation:
The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".

Constraints:
2 <= S.length <= 100
S will only contain lowercase letters and digits 2 through 9.
S starts with a letter.
1 <= K <= 10^9
It's guaranteed that K is less than or equal to the length of the decoded string.
The decoded string is guaranteed to have less than 2^63 letters.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int64_t sz = 0, n = S.size();
        char ch, last;
        string s;
        for (int i = 0; i < n && sz < K; ++i) {
            ch = S[i];
            if (isdigit(ch)) {
                int64_t diff = ch - '0';
                if (sz < K) {
                    ostringstream oss;
                    for (int i = 0; i < diff; ++i)
                        oss << s;
		    s = oss.str();
                }
                if (diff * sz >= K) {
                    if (K <= 100)
                        return string(1, s[K-1]);
                    int mod = K % sz;
                    if (mod == 0)
                        return string(1, last);
                    return decodeAtIndex(S, mod);
                }
                sz *= diff;
           } else {
                ++sz;
                last = ch;
                if (K <= 100)
                    s.push_back(ch);
            }
        }

        if (sz == K)
            return string(1, last);
        return decodeAtIndex(S, sz - K);
    }
};

int main() {
    Solution sol;
    string S;
    int K;

    // Output: "o"
    S = "leet2code3", K = 10;
    //cout << sol.decodeAtIndex(S, K) << endl;

    // Output: "h"
    S = "ha22", K = 5;
    //cout << sol.decodeAtIndex(S, K) << endl;

    // Output: "a"
    S = "a2345678999999999999999", K = 1;
    //cout << sol.decodeAtIndex(S, K) << endl;

    // Output: g
    S = "a2b3c4d5e6f7g8h9", K = 69280;
    cout << sol.decodeAtIndex(S, K) << endl;

    return 0;
}
