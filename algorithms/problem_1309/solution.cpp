/*
1309. Decrypt String from Alphabet to Integer Mapping
Easy

Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

Example 1:
Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

Example 2:
Input: s = "1326#"
Output: "acz"

Example 3:
Input: s = "25#"
Output: "y"

Example 4:
Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"

Constraints:

1 <= s.length <= 1000
s[i] only contains digits letters ('0'-'9') and '#' letter.
s will be valid string such that mapping is always possible.

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
    string freqAlphabets(string s) {
        int i = 0, sz = s.size();
        ostringstream oss;
        while (i < sz) {
            int index;
            if (i + 2 < sz && s[i+2] == '#') {
                index = (s[i] - '0') * 10 + s[i+1] - '1';
                i += 3;
            } else {
                index = (s[i] - '1');
                ++i;
            }
            char ch = 'a' + index;
            oss << ch;
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    string s;

    // Output: "jkab"
    s = "10#11#12";

    // Output: "acz"
    s = "1326#";

    // Output: "y"
    //s = "25#";

    // Output: "abcdefghijklmnopqrstuvwxyz"
    // s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";

    cout << "Result: " << sol.freqAlphabets(s) << endl;

    return 0;
}
