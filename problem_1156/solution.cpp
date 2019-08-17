/*
1156. Swap For Longest Repeated Character Substring
Medium

Given a string text, we are allowed to swap two of the characters in the string. Find the
length of the longest substring with repeated characters.

Example 1:
Input: text = "ababa"
Output: 3
Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa", which its length is 3.

Example 2:
Input: text = "aaabaaa"
Output: 6
Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa", which its length is 6.

Example 3:
Input: text = "aaabbaaa"
Output: 4

Example 4:
Input: text = "aaaaa"
Output: 5
Explanation: No need to swap, longest repeated character substring is "aaaaa", length is 5.

Example 5:
Input: text = "abcdef"
Output: 1
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {

        if (text.empty())
            return 0;
        
        vector<int> len;
        vector<char> chars;
        map<char, int> appears;
        char curr_char, prev_char = text[0];
        int prev, curr, res = 0;

        auto lamb = [&] () {
            int curr_len = curr - prev;
            int vlen = chars.size();
            /*
            cout << "prev: " << prev << ", curr; " << curr << ", vlen: " << vlen << ", prev_char: " << prev_char << ", appears: " << appears[prev_char] << endl;
            copy(begin(chars), end(chars), ostream_iterator<char>(cout, ", "));
            cout << endl;
            copy(begin(len), end(len), ostream_iterator<int>(cout, ", "));
            cout << endl;
            */
            if (vlen >= 2) {
                if (chars[vlen-2] == prev_char) {
                    int temp = curr_len;
                    if (len[vlen-1] == 1) {
                        if (appears[prev_char] > 1 || text.find(prev_char, curr) != string::npos) {
                            temp += len[vlen-2] + 1;
                        } else {
                            temp += len[vlen-2];
                        }
                    } else
                        ++temp;
                    res = max(res, temp);
                }
                len.erase(begin(len));
                chars.erase(begin(chars));
            } else {
                if (text.find(prev_char, curr) != string::npos)
                    res = max(res, curr_len + 1);
                else
                    res = max(res, curr_len);
            }
        };
        
        for (prev = curr = 0; curr < static_cast<int>(text.size()); ++curr) {
            curr_char = text[curr];

            if (prev_char != curr_char) {
                lamb();
                len.emplace_back(curr - prev);
                chars.emplace_back(prev_char);
                ++appears[prev_char];
                prev = curr;
                prev_char = text[prev];
            }
        }
        
        if (prev < curr) {
            lamb();
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    string text;

    // Output: 3
    text = "ababa";

    // Output: 6
    //text = "aaabaaa";

    // Output: 4
    //text = "aaabbaaa";

    // Output: 5
    //text = "aaaaa";

    // Output: 1
    //text = "abcdef";

    // 42 / 47 test cases passed.
    // Expected: 11
    //text = "baaabaaaaaaabaab";

    // 45 / 47 test cases passed.
    // Expected: 7
    //text = "aaaaabbbbbbaabbaabbaaabbbbab";
    
    cout << "Result: " << sol.maxRepOpt1(text) << endl;
    
    return 0;
}

