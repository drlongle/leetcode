/*
1647. Minimum Deletions to Make Character Frequencies Unique
Medium

A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example,
in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

Example 1:
Input: s = "aab"
Output: 0
Explanation: s is already good.

Example 2:
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".

Example 3:
Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end
(i.e. frequency of 0 is ignored).

Constraints:
1 <= s.length <= 105
s contains only lowercase English letters.
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26);
        for (char c: s)
            ++cnt[c-'a'];
        unordered_set<int> tabl;
        int res = 0;
        for (int i: cnt) {
            while (i > 0) {
                if (tabl.emplace(i).second) {
                    break;
                } else
                    ++res, --i;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 0
    s = "aab";
    cout << sol.minDeletions(s) << endl;

    // Output: 2
    s = "aaabbbcc";
    cout << sol.minDeletions(s) << endl;

    // Output: 2
    s = "ceabaacb";
    cout << sol.minDeletions(s) << endl;

    return 0;
}
