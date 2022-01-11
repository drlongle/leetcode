/*
844. Backspace String Compare

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:
1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.

Follow up:
Can you solve it in O(N) time and O(1) space?
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
    string process(string& s) {
        string res;
        for (char ch: s) {
            if (ch != '#')
                res.push_back(ch);
            else if (!res.empty())
                res.pop_back();
        }
        return res;
    }
    
    bool backspaceCompare(string S, string T) {
        return process(S) == process(T);
    }
};

int main() {
    Solution sol;
    string S, T;

    // Output: true
    S = "ab#c", T = "ad#c";
    cout << boolalpha << sol.backspaceCompare(S, T) << endl;

    // Output: true
    S = "ab##", T = "c#d#";
    cout << boolalpha << sol.backspaceCompare(S, T) << endl;
    
    // Output: true
    S = "a##c", T = "#a#c";
    cout << boolalpha << sol.backspaceCompare(S, T) << endl;
    
    // Output: false
    S = "a#c", T = "b";
    cout << boolalpha << sol.backspaceCompare(S, T) << endl;
    
    return 0;
}
