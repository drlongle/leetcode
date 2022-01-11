/*
917. Reverse Only Letters

Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

Example 1:
Input: s = "ab-cd"
Output: "dc-ba"

Example 2:
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

Constraints:
1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ) {
            while (i < j && !isalpha(s[i]))
                ++i;
            while (i < j && !isalpha(s[j]))
                --j;
            if (i < j) {
                swap(s[i], s[j]);
                ++i, --j;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: "dc-ba"
    s = "ab-cd";
    cout << sol.reverseOnlyLetters(s) << endl;

    // Output: "j-Ih-gfE-dCba"
    s = "a-bC-dEf-ghIj";
    cout << sol.reverseOnlyLetters(s) << endl;

    // Output: "Qedo1ct-eeLg=ntse-T!"
    s = "Test1ng-Leet=code-Q!";
    cout << sol.reverseOnlyLetters(s) << endl;

    return 0;
}
