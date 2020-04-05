/*
1405. Longest Happy String
Medium

A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which satisfies following conditions:

s is happy and longest possible.
s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
s will only contain 'a', 'b' and 'c' letters.
If there is no such string s return the empty string "".

Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:
Input: a = 2, b = 2, c = 1
Output: "aabbc"

Example 3:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.

Constraints:
0 <= a, b, c <= 100
a + b + c > 0
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
    map<char, int> cnt;

    string get(char excluded) {
        if (cnt.empty())
            return "";
        if (cnt.size() == 1)
            return string(min(2, cnt.begin()->second), cnt.begin()->first);
        auto lambda =  [this, excluded] (auto&p1, auto& p2) {return (p2.first != excluded && p1.second < p2.second) || p1.first == excluded;};
        auto max_it = max_element(begin(cnt), end(cnt), [this] (auto&p1, auto&p2) {return p1.second < p2.second;});
        auto it = max_element(begin(cnt), end(cnt), lambda);
        
        int char_cnt;
        if (it->second == max_it->second)
            char_cnt = min(2, it->second);
        else
            char_cnt = min(1, it->second);                                                
        int ch = it->first;
        string res = string(char_cnt, ch);
        it->second -= char_cnt;
        if (it->second == 0)
            cnt.erase(it);
        return res + get(ch);;
    }
    
    string longestDiverseString(int a, int b, int c) {
        if (a > 0)
            cnt.insert({'a', a});
        if (b > 0)
            cnt.insert({'b', b});
        if (c > 0)
            cnt.insert({'c', c});
        return get('*');
    }
};

int main() {
    Solution sol;
    int a, b, c;

    // Output: "ccaccbcc"
    a = 1, b = 1, c = 7;
    //cout << sol.longestDiverseString(a, b, c) << endl;
    
    // Output: "aabbc"
    a = 2, b = 2, c = 1;
    //cout << sol.longestDiverseString(a, b, c) << endl;
    
    // Output: "aabaa"
    a = 7, b = 1, c = 0;
    cout << sol.longestDiverseString(a, b, c) << endl;

    // Expected: "ccbccbbccbbccbbccbc"
    a = 0, b = 8, c = 11;
    cout << sol.longestDiverseString(a, b, c) << endl;
    
    return 0;
}
