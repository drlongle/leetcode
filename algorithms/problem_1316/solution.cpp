/*
1316. Distinct Echo Substrings
Hard

Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string). 

Example 1:
Input: text = "abcabcabc"
Output: 3
Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".

Example 2:
Input: text = "leetcodeleetcode"
Output: 2
Explanation: The 2 substrings are "ee" and "leetcodeleetcode".

Constraints:
1 <= text.length <= 2000
text has only lowercase English letters.
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
    int distinctEchoSubstrings(string text) {
        unordered_set<string> res;
        size_t sz = text.size();
        for (size_t i = 0; i < sz-1; ++i) {
            char ch = text[i];
            size_t j = i;
            while (true) {
                j = text.find(ch, j+1);
                if (j == string::npos)
                    break;
                size_t len = j - i;
                if (j + len > sz)
                    break;
                string_view sv1(text.c_str() + i, len);
                string_view sv2(text.c_str() + j, len);
                if (sv1 == sv2)
                    res.emplace(text.substr(i, len));
            }
        }
        
        return res.size();
    }
};

int main() {
    Solution sol;
    string text;

    // Output: 3
    text = "abcabcabc";

    // Output: 2
    text = "leetcodeleetcode";

    // Output: 2
    text = "aa";
    
    // Output: 2
    text = "baaaac";
    
    // Output: 3
    text = "baaaaac";
    
    cout << "Result: " << sol.distinctEchoSubstrings(text) << endl;

    return 0;
}
