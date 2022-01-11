/*
1358. Number of Substrings Containing All Three Characters
Medium

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c. 

Example 1:
Input: s = "abcabc"
Output: 10

Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:
Input: s = "aaacb"

Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:
Input: s = "abc"
Output: 1

Constraints:
3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
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
    int numberOfSubstrings(string s) {
        map<char, int> last_pos;
        int res = 0, sz = s.size();
        for (int i = 0; i < sz; ++i) {
            char ch = s[i];
            auto reduced = last_pos;
            reduced.erase(ch);
            if (reduced.size() == 2) {
                int tail = min(reduced.begin()->second, reduced.rbegin()->second);
                res += tail + 1;
            }
            last_pos[ch] = i;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 10
    s = "abcabc";

    // Output: 3
    s = "aaacb";

    // Output: 1
    s = "abc";

    cout << sol.numberOfSubstrings(s) << endl;
    
    return 0;
}
