/*
936. Stamping The Sequence
Hard

You want to form a target string of lowercase letters.

At the beginning, your sequence is target.length '?' marks.  You also have a stamp of lowercase letters.

On each turn, you may place the stamp over the sequence, and replace every letter in the sequence with
the corresponding letter from the stamp.  You can make up to 10 * target.length turns.

For example, if the initial sequence is "?????", and your stamp is "abc",  then you may make
"abc??", "?abc?", "??abc" in the first turn.  (Note that the stamp must be fully contained in the
boundaries of the sequence in order to stamp.)

If the sequence is possible to stamp, then return an array of the index of the left-most letter
being stamped at each turn.  If the sequence is not possible to stamp, return an empty array.

For example, if the sequence is "ababc", and the stamp is "abc", then we could return the answer [0, 2],
corresponding to the moves "?????" -> "abc??" -> "ababc".

Also, if the sequence is possible to stamp, it is guaranteed it is possible to stamp within
10 * target.length moves.  Any answers specifying more than this number of moves will not be accepted.

Example 1:
Input: stamp = "abc", target = "ababc"
Output: [0,2]
([1,0,2] would also be accepted as an answer, as well as some other answers.)

Example 2:
Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]

Note:
1 <= stamp.length <= target.length <= 1000
stamp and target only contain lowercase letters.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:

    vector<int> movesToStamp(string& stamp, string target) {
        vector<int> res;
        bool matched = true;
        int i, j, ssize = stamp.size(), tsize = target.size();
        do {
            matched = false;
            for (i = 0; i <= tsize - ssize; ++i) {
                bool has_char = false;
                for (j = 0; j < ssize; ++j) {
                    if (target[i+j] != stamp[j] && target[i+j] != '*')
                        break;
                    has_char |= isalpha(target[i+j]);
                }
                if (j == ssize && has_char) {
                    matched = true;
                    res.push_back(i);
                    fill(begin(target) + i, begin(target) + i + ssize, '*');
                }
            }
        } while (matched);

        if (!all_of(begin(target), end(target), [] (char ch) {return ch == '*';}))
            return {};

        reverse(std::begin(res), std::end(res));

        return res;
    }
};

int main() {
    string stamp, target;
    vector<int> res;

    // Output: [0,2]
    {
        Solution sol;
        stamp = "abc", target = "ababc";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [3,0,1]
    {
        Solution sol;
        stamp = "abca", target = "aabcaca";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: []
    {
        Solution sol;
        stamp = "aye", target = "eyeye";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: []
    {
        Solution sol;
        stamp = "lemk", target = "lleme";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [3,2,0,5,1,4]
    {
        Solution sol;
        stamp = "ffebb", target = "fffeffebbb";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,23,26,25,31,30,28,27,33,29,32]
    {
        Solution sol;
        stamp = "ffebb", target = "fffffffffffffffffffffffffffffffeffebbb";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [5,2,8,6,3,0,7,4,1]
    {
        Solution sol;
        stamp = "de", target = "ddeddeddee";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: []
    {
        Solution sol;
        stamp = "mda", target = "mdadddaaaa";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [8,11,7,1,12,10,6,4,2,13,9,5,3,0]
    {
        Solution sol;
        stamp = "aq", target = "aqaaqaqqqaqqaaq";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [1,10,2,12,9,7,5,3,13,11,8,6,4,0]
    {
        Solution sol;
        stamp = "qr", target = "qrqqqrqrqrrqrqr";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: [20,19,18,17,37,16,14,36,21,15,12,35,33,22,13,10,0,34,31,25,23,11,8,1,29,32,27,24,9,6,4,2,30,26,7,3,28,5]
    {
        Solution sol;
        stamp = "abc", target = "aaaababcbcbcbcbcbccccaaaabababcbcbcbcccc";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    {
        Solution sol;
        stamp = "zbs", target = "zbzbsbszbssbzbszbsss";
        res = sol.movesToStamp(stamp, target);
        copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
