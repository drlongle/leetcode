/*
1370. Increasing Decreasing String
Easy

Given a string s. You should re-order the string using the following algorithm:

1. Pick the smallest character from s and append it to the result.
2. Pick the smallest character from s which is greater than the last appended character to the result and append it.
3. Repeat step 2 until you cannot pick more characters.
4. Pick the largest character from s and append it to the result.
5. Pick the largest character from s which is smaller than the last appended character to the result and append it.
6. Repeat step 5 until you cannot pick more characters.
7. Repeat the steps from 1 to 6 until you pick all characters from s.

In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.

Example 1:
Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"

Example 2:
Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.

Example 3:
Input: s = "leetcode"
Output: "cdelotee"

Example 4:
Input: s = "ggggggg"
Output: "ggggggg"

Example 5:
Input: s = "spo"
Output: "ops"

Constraints:
1 <= s.length <= 500
s contains only lower-case English letters.
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
#include <memory>
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
    string sortString(string s) {
        multiset<char> forward;
        multiset<char, greater<char>> backward;
        size_t sz = s.size();
        for (char ch: s) {
            forward.emplace(ch);
            backward.emplace(ch);
        }
        
        ostringstream oss;
        while (oss.str().size() < sz) {
            auto it = forward.begin();
            while (it != forward.end()) {
                char ch = *it;
                oss << ch;
                forward.erase(it);
                backward.erase(backward.find(ch));
                it = forward.upper_bound(ch);
            }
            auto it2 = backward.begin();
            while (it2 != backward.end()) {
                char ch = *it2;
                oss << ch;
                backward.erase(it2);
                forward.erase(forward.find(ch));
                it2 = backward.upper_bound(ch);
            }
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    string s;

    // Output: "abccbaabccba"
    s = "aaaabbbbcccc";
    cout << sol.sortString(s) << endl;
    
    // Output: "art"
    s = "rat";
    cout << sol.sortString(s) << endl;
    
    // Output: "cdelotee"
    s = "leetcode";
    cout << sol.sortString(s) << endl;
    
    // Output: "ggggggg"
    s = "ggggggg";
    cout << sol.sortString(s) << endl;
    
    // Output: "ops"
    s = "spo";
    cout << sol.sortString(s) << endl;
        
    return 0;
}
