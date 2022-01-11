/*
1417. Reformat The String
Easy

Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

Example 1:
Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.

Example 2:
Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.

Example 3:
Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.

Example 4:
Input: s = "covid2019"
Output: "c2o0v1i9d"

Example 5:
Input: s = "ab123"
Output: "1a2b3"

Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    string reformat(string s) {
        vector<char> digits, letters;
        for (char ch: s) {
            if (isdigit(ch))
                digits.push_back(ch);
            else
                letters.push_back(ch);
        }
        int dsz = digits.size(), lsz = letters.size();
        if (abs(dsz - lsz) > 1)
            return "";

        if (lsz > dsz) {
            swap(digits, letters);
            dsz = lsz;
        }
        ostringstream oss;
        for (int i = 0; i < dsz; ++i) {
            oss << digits[i];
            if (i < letters.size())
                oss << letters[i];                
        }

        return oss.str();
    }
};


int main() {
    Solution sol;
    string s;

    // Output: "0a1b2c"
    s = "a0b1c2";
    cout << sol.reformat(s) << endl;

    // Output: ""
    s = "leetcode";
    cout << sol.reformat(s) << endl;
    
    // Output: ""
    s = "1229857369";
    cout << sol.reformat(s) << endl;
    
    // Output: "c2o0v1i9d"
    s = "covid2019";
    cout << sol.reformat(s) << endl;
    
    // Output: "1a2b3"
    s = "ab123";
    cout << sol.reformat(s) << endl;    

    return 0;
}
